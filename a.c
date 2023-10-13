#include <stdio.h>
#include <limits.h>
#include <string.h>

#define NUM_CITIES 7

char cityNames[NUM_CITIES][50];

// Function to find the index of a city in the list of city names
int findCityIndex(const char *cityName) {
    for (int i = 0; i < NUM_CITIES; i++) {
        if (strcmp(cityName, cityNames[i]) == 0) {
            return i;
        }
    }
    return -1; // Return -1 if city not found
}

// Function to find the minimum distance vertex not included in the shortest path set
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < NUM_CITIES; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the shortest path from source to destination
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf(" -> %s", cityNames[j]);
}

// Function to find the shortest path and distance between cities
void shortestPath(int graph[NUM_CITIES][NUM_CITIES], const char *srcCity, const char *destCity, int speed) {
    int src = findCityIndex(srcCity);
    int dest = findCityIndex(destCity);

    if (src == -1 || dest == -1) {
        printf("Invalid city names. Please enter valid city names.\n");
        return;
    }

    int dist[NUM_CITIES];
    int sptSet[NUM_CITIES];
    int parent[NUM_CITIES];

    // Initialize arrays
    for (int i = 0; i < NUM_CITIES; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[src] = -1;
    }

    // Distance of source city from itself is always 0
    dist[src] = 0;

    // Find shortest path for all cities
    for (int count = 0; count < NUM_CITIES - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < NUM_CITIES; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Calculate the shortest distance
    int shortestDistance = dist[dest];

    // Calculate the time taken to travel the shortest distance at the given speed
    double time = (double)shortestDistance / speed;

    // Print the shortest distance and path
    printf("Fastest distance from %s to %s : %d km\n", srcCity, destCity, shortestDistance);
    printf("Fastest driving route : %s", srcCity);
    printPath(parent, dest);
    printf("\n");
    printf("Time taken to travel at %d km/h: %.2lf hours\n", speed, time);
}

int main() {
    // Input city names
    
    printf("Enter the names of %d cities:\n", NUM_CITIES);
    for (int i = 0; i < NUM_CITIES; i++) {
        printf("Enter the name of City %d : ", i+1);
        scanf("%s", cityNames[i]);
    }
    int graph[NUM_CITIES][NUM_CITIES];
    // Defining distances between cities
    printf("Enter Values in Graph\n");
                for(int i=0;i<NUM_CITIES;i++){
                    for(int j=0;j<NUM_CITIES;j++){
                        scanf("%d",&graph[i][j]);
                    }
                }

    // int graph[NUM_CITIES][NUM_CITIES] = {
    //     {0, 100, 200, 0, 0},
    //     {100, 0, 150, 200, 0},
    //     {200, 150, 0, 50, 0},
    //     {0, 200, 50, 0, 100},
    //     {0, 0, 0, 100, 0}
    // };

    char sourceCity[50], destCity[50];
    int speed;


    // Get user input for source and destination cities
    printf("Enter the source city: ");
    scanf("%s", sourceCity);
    printf("Enter the destination city: ");
    scanf("%s", destCity);

    // Get user input for speed
    printf("Enter the speed of travel (in kilometers per hour): ");
    scanf("%d", &speed);

    shortestPath(graph, sourceCity, destCity, speed);

    return 0;
}
