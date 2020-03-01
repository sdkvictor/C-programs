#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

typedef struct Node{ 
    char value[50]; 
    struct Node* next; 
} Node;

typedef struct NodeList{ 
    Node* head;
    Node* tail; 
} NodeList;

typedef struct Agent{ 
   char name[50]; 
   char lastName[50]; 
   int age; 
   NodeList activos;
   NodeList missions;
   struct Agent* next;
} Agent;

typedef struct{ 
    Agent* head;
    Agent* tail;
} Agents;

Agents agentes;

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
    int op;
    char name[50]; 
    char lastName[50]; 
    int age;
    bool end = false;
    agentes.head = NULL;    

    while(!end){
    printf("MENU \n");
    printf("Ingresa el número de la opción a ejecutar: \n");
    printf("1. Crear un agente \n");
    printf("2. Eliminar un agente \n");
    printf("3. Mostrar agentes \n");
    printf("4. Salir \n");
    scanf("%d", &op);
        switch (op){
            case 1:
                printf("Ingresa el nombre del agente:");
                scanf("%s",name);
                printf("Ingresa el apellido del agente:");
                scanf("%s",lastName);
                printf("Ingresa la edad del agente:");
                scanf("%d", &age);
                newAgent(name, lastName, age);
                break;
            case 2:
                printf("Ingresa el nombre del agente a eliminar:");
                scanf("%s",name);
                printf("Ingresa el apellido del agente:");
                scanf("%s",lastName);
                deleteAgent(name, lastName);
                break;
            case 3:
                displayAgents();
                break;
            case 4:
                end = true;
                break;
            }
    }
}

void displayList(Node* n){
    while (n != NULL) { 
        printf("%s", n->value); 
        n = n->next; 
    } 
}

void newAgent(char name[50], char lastName[50], int age){
    Agent *agent;
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
    int n;
    char mission[50];
    printf("Ingresa la cantidad de misiones del agente:");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Ingresa el código de la misión %d :", i+1);
        scanf("%s", mission);
        //validate mission
        while(!validateMission(mission)){
            printf("Error: Please enter a valid mission ID (3 letters followed by 9 whole numbers): \n");
            scanf("%s", mission);
        }

        addMission(agent, mission, i);    
    }
    
    //adding actives
    char activo[50];
    printf("Ingresa la cantidad de activos del agente:");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Ingresa el código del activo %d :", i+1);
        scanf("%s", activo);
        //validate active
        while(!validateActive(activo)){
            printf("Error: Please enter a valid active ID (4 letters followed by 9 whole numbers): \n");
            scanf("%s", activo);
        }
        
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
    agentes.tail->next = NULL;
}

void addMission(Agent* agent, char mission[50], int i){
        //set new empty node pointer pointing to NULL
        Node* newMission = NULL;
        newMission = (Node*)malloc(sizeof(Node));
        strcpy(newMission->value, mission);  
        newMission->next = NULL;

        if(i==0){
            agent->missions.head = newMission;
            agent->missions.tail = agent->missions.head;
        }
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

        if(i==0){
            agent->activos.head = newActive;
            agent->activos.tail = agent->activos.head;
        }
        else{
            agent->activos.tail->next = newActive;
            agent->activos.tail = newActive;
        } 
}

bool validateMission(char mission[50]){
    bool result;
    if (strlen(mission) < 12){
        return false;
    }

    for(int i=0; i<3; i++){
        int errors;
        if(mission[i] < 'A' || (mission[i] > 'Z' && mission[i] < 'a') || mission[i] > 'z'){
            return false;
        } 
    }

    for(int i=3; i<12; i++){
        if(mission[i] < '0' || mission[i]>'9'){
            return false;
        }
    }

    return true;
}

bool validateActive(char activo[50]){
    bool result;
    if (strlen(activo) < 12){
        return false;
    }

    for(int i=0; i<4; i++){
        int errors;
        if(activo[i] < 'A' || (activo[i] > 'Z' && activo[i] < 'a') || activo[i] > 'z'){
            return false;
        } 
    }

    for(int i=4; i<13; i++){
        if(activo[i] < '0' || activo[i]>'9'){
            return false;
        }
    }

    return true;
}

void displayAgents(){
    Agent* currentAgent = agentes.head;
    int count = 1;
    while(currentAgent!=NULL){
        displayAgent(currentAgent, count);
        currentAgent = currentAgent->next;
        count++;
        printf("\n");
    }
}

void displayAgent(Agent* agent, int count){
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

void deleteAgent(char name[50], char lastName[50]){
    Agent* currentAgent = agentes.head;
    Agent* prevAgent = agentes.head;
    bool found = false;
    int count = 1;
    while(currentAgent!=NULL && !found){
        printf("Looking for %s %s \n", name, lastName);       
        //first iteration 
        if(count == 1){
            //found in the first node of the list
            if(strcmp(currentAgent->name, name)==0 && strcmp(currentAgent->lastName, lastName)==0){
                found = true;
                agentes.head = agentes.head->next;
                currentAgent->next = NULL;
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
                prevAgent->next = currentAgent->next;
                currentAgent->next = NULL;
                free(currentAgent);
                currentAgent = prevAgent->next;
                
            }
            else{
                prevAgent =prevAgent->next;
                currentAgent = currentAgent->next;
            }
        }
        count++;
    }
    if(!found){
        printf("Error: Agent was not found \n");
    }
    else{
        printf("Agent deleted successfully! \n");
    }
}
