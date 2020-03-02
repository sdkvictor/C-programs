//
// Author: Victor Andrés Villarreal Grimaldo
// ID: A01039863
// Date: 1/03/2020
//
// Create agent structures to store in lists and delete agents from such list

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

//Node structure
// stores a character chain with the mission code or the active code
// next pointer pointing to the next element in the linked list
typedef struct Node{ 
    char value[50]; 
    struct Node* next; 
} Node;

// linked list of nodes with a head (start of the list) and tail (end of the list) pointers
typedef struct NodeList{ 
    Node* head;
    Node* tail; 
} NodeList;

//Agent structure node
// Name and last name of the agent
// Age of the agent
// Linked list of actives and list of missions
typedef struct Agent{ 
   char name[50]; 
   char lastName[50]; 
   int age; 
   NodeList activos;
   NodeList missions;
   struct Agent* next;
} Agent;

//Agents linked list with a head and tail poiting to the first and the last node of the list respectively
typedef struct{ 
    Agent* head;
    Agent* tail;
} Agents;

//Linked list of all agents
Agents agentes;

//Declaration of functions to be documented and defined after the main function
void displayList(Node* n);

void newAgent(char name[50], char lastName[50], int age);

void addMission(Agent* agent, char value[50], int i);

void addActive(Agent* agent, char activo[50], int i);

bool validateMission(char mission[50]);

bool validateActive(char activo[50]);

void displayAgents();

void displayAgent(Agent* agent, int count);

void deleteAgent(char name[50], char lastName[50]);

int main(){
    //option from the menu
    int op;
    //name of the agent
    char name[50]; 
    //last name of the agent
    char lastName[50]; 
    //Age of the agent
    int age;
    //Condition of the program being exited or not
    bool end = false;
    //Initialize the beginning of the agents list pointing to NULL
    agentes.head = NULL;    

    while(!end){
    //Display menu with options
    printf("MENU \n");
    printf("Enter the number of the action to perform: \n");
    printf("1. Create new agent \n");
    printf("2. Delete agent \n");
    printf("3. Show agents \n");
    printf("4. Exit \n");
    scanf("%d", &op);
        switch (op){
            //Create new agent
            case 1:
                printf("Enter the agent's name:");
                scanf("%s",name);
                printf("Enter the agent's last name:");
                scanf("%s",lastName);
                printf("Enter the agent's age:");
                scanf("%d", &age);
                //Create the agent node and add it to the list with the data provided
                newAgent(name, lastName, age);
                break;
            //Delete agent
            case 2:
                printf("Enter the name of the agent to delete:");
                scanf("%s",name);
                printf("Enter the agent's last name:");
                scanf("%s",lastName);
                //Delete the specified agent
                deleteAgent(name, lastName);
                break;
            //Display agents
            case 3:
                displayAgents();
                break;
            //Exit the program
            case 4:
                end = true;
                break;
            }
    }
}

//Display the list of missions or actives of an agent
void displayList(Node* n){
    //Until reaching the end of the list
    while (n != NULL) { 
        printf("%s", n->value); 
        n = n->next; 
    } 
}

void newAgent(char name[50], char lastName[50], int age){
    //Node for the new agent
    Agent *agent;
    //Mission code
    char mission[50];
    //Active code
    char activo[50];
    //Amount of missions and actives
    int n;
    //memory allocation and initialization of nulls
    agent = (struct Agent*)malloc(sizeof(struct Agent));
    agent->activos.head = NULL;
    agent->activos.tail = NULL;
    agent->missions.head = NULL;
    agent->missions.tail = NULL;

    //Set parameters of age, name and last name
    agent->age = age;
    strcpy(agent->name,name);
    strcpy(agent->lastName,lastName);

    //adding missions
    printf("Enter the amount of missions of the agent:");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        //input mission code
        printf("Enter the code of the mission %d :", i+1);
        scanf("%s", mission);
        //validate mission
        while(!validateMission(mission)){
            printf("Error: Please enter a valid mission ID (3 letters followed by 9 whole numbers): \n");
            scanf("%s", mission);
        }
        //Add the mission to the list
        addMission(agent, mission, i);    
    }
    
    //adding actives
    printf("Enter the amount of actives of the agent:");
    //input active code
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter the code of the active %d :", i+1);
        scanf("%s", activo);
        //validate active
        while(!validateActive(activo)){
            printf("Error: Please enter a valid active ID (4 letters followed by 9 whole numbers): \n");
            scanf("%s", activo);
        }
        //Add the active to the list
        addActive(agent, activo, i);    
    }

    //adding agent to agents list
    if(agentes.head == NULL){
            agentes.head = agent;
            agentes.tail = agent;
    }
    else{
        agentes.tail->next = agent;
        agentes.tail = agent;
    } 
    //set end of the list pointing to null
    agentes.tail->next = NULL;
}

//Adds a new mission to the linked list of the specified agent
//agent - agent owner of the list
//mission - mission code to be validated and added
//i - number of element in the list
void addMission(Agent* agent, char mission[50], int i){
        //set new empty node pointer pointing to NULL
        Node* newMission = NULL;
        newMission = (Node*)malloc(sizeof(Node));
        strcpy(newMission->value, mission);  
        newMission->next = NULL;
        //If its the first element
        if(i==0){
            agent->missions.head = newMission;
            agent->missions.tail = agent->missions.head;
        }
        //not the first element
        else{
            agent->missions.tail->next = newMission;
            agent->missions.tail = newMission;
        } 
}

void addActive(Agent* agent, char activo[50], int i){
        //set new empty node pointer pointing to NULL
        Node* newActive = NULL;
        newActive = (Node*)malloc(sizeof(Node));
        strcpy(newActive->value, activo);  
        newActive->next = NULL;
        //if its the first element
        if(i==0){
            agent->activos.head = newActive;
            agent->activos.tail = agent->activos.head;
        }
        //not the first element
        else{
            agent->activos.tail->next = newActive;
            agent->activos.tail = newActive;
        } 
}

bool validateMission(char mission[50]){
    bool result;
    //length is less than 12
    if (strlen(mission) < 12){
        return false;
    }
    //Validate first 3 letters
    for(int i=0; i<3; i++){
        if(mission[i] < 'A' || (mission[i] > 'Z' && mission[i] < 'a') || mission[i] > 'z'){
            return false;
        } 
    }
    //Validate last 9 digits
    for(int i=3; i<12; i++){
        if(mission[i] < '0' || mission[i]>'9'){
            return false;
        }
    }

    return true;
}

bool validateActive(char activo[50]){
    bool result;
    //length is less than 13
    if (strlen(activo) < 13){
        return false;
    }
    //Validate first 4 letters
    for(int i=0; i<4; i++){
        if(activo[i] < 'A' || (activo[i] > 'Z' && activo[i] < 'a') || activo[i] > 'z'){
            return false;
        } 
    }
    //Validate last 9 digits
    for(int i=4; i<13; i++){
        if(activo[i] < '0' || activo[i]>'9'){
            return false;
        }
    }

    return true;
}

void displayAgents(){
    //point to the start of the list
    Agent* currentAgent = agentes.head;
    //count of the number of agents displayed
    int count = 1;
    //Until reaching the end of the list
    while(currentAgent!=NULL){
        //Display the agent's information
        displayAgent(currentAgent, count);
        //move to the next agent and increase the amount displayed
        currentAgent = currentAgent->next;
        count++;
        printf("\n");
    }
}

//displays one agent and their data.
//receives the agent node and the amount of agents displayed so far
void displayAgent(Agent* agent, int count){
    //Display name, last name and age
    printf("Agent %d \n", count);
    printf("Name: %s \n", agent->name);
    printf("Last name: %s \n", agent->lastName);
    printf("Age: %d \n", agent->age);

    printf("Missions: \n");
    //display missions
    Node* currentMission = agent->missions.head;
    while(currentMission!=NULL){
        printf("%s \n", currentMission->value);
        currentMission = currentMission->next;
    }

    printf("Actives: \n");
    //display actives
    Node* currentActive = agent->activos.head;
    while(currentActive!=NULL){
        printf("%s \n", currentActive->value);
        currentActive = currentActive->next;
    }
}

//delete an agent from the agents list
//receives the name and alst name of the agent to be deleted
void deleteAgent(char name[50], char lastName[50]){
    //Two pointers pointing to the start of the agents list
    Agent* currentAgent = agentes.head;
    Agent* prevAgent = agentes.head;
    //set found condition to not found yet (false)
    bool found = false;
    //current position of the node checked
    int count = 1;
    while(currentAgent!=NULL && !found){
        printf("Looking for %s %s \n", name, lastName);       
        //first iteration 
        if(count == 1){
            //found in the first node of the list
            if(strcmp(currentAgent->name, name)==0 && strcmp(currentAgent->lastName, lastName)==0){
                //Agent was found
                found = true;
                //move pointers to skip the deleted node
                agentes.head = agentes.head->next;
                currentAgent->next = NULL;
                //free the memory allocated to the deleted agent
                free(currentAgent);
                currentAgent = agentes.head;
                prevAgent = agentes.head;
            }
            else{
                currentAgent = currentAgent->next;
            }
        }
        else{
            if(strcmp(currentAgent->name, name)==0 && strcmp(currentAgent->lastName, lastName)==0){
                found = true;
                //move pointers to skip the deleted node
                prevAgent->next = currentAgent->next;
                currentAgent->next = NULL;
                //free the memory allocated to the deleted agent
                free(currentAgent);
                //Move to the next node
                currentAgent = prevAgent->next;
                
            }
            else{
                //Move to the next node, and move both pointers forward
                prevAgent =prevAgent->next;
                currentAgent = currentAgent->next;
            }
        }
        //increase the nodes checked
        count++;
    }
    //Agent was not found
    if(!found){
        printf("Error: Agent was not found \n");
    }
    //Agent was found
    else{
        printf("Agent deleted successfully! \n");
    }
}
