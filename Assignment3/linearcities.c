/*Read the data from file 'cities.txt' containing names of 10 cities and their STD codes.
Accept a name of the city from user and use linear search algorithm to check whether the
name is present in the file and output the STD code, otherwise output “city not in the list”.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cities
{
    char cityname[50];
    int stdcode;
};


int linearsearch(struct Cities city[], int n, char key[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(city[i].cityname,key)==0) {
            return city[i].stdcode;
        }
    }
    return -1;
}

int main() {
    char name[50];
    int p;
    FILE *fp;
    struct Cities cities[100];
    int n = 10,i;
    fp = fopen("cities.txt", "r");
    if (fp== NULL) {
        printf("Error opening cities.txt");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fscanf(fp, "%s %d", cities[i].cityname, &cities[i].stdcode);
    }
    
    printf("Enter a city name to search:\n");
    gets(name);
    p=linearsearch(cities,10,name);
 
    if (p == -1) {
        printf("The city was not found in the list.\n");
    } else {
        printf("%s %d",name,p);
    }

    fclose(fp);

    

    return 0;
}
