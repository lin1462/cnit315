#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

// stores weather data for current time and place
struct WeatherData {
    char time[30];              
    char city[30];
    char country[30];
    int temp;
    int feelsTemp;
    int minTemp;
    int maxTemp;
    int wind;
    int percipitation;
};

struct WeatherData* cities[MAX]; // array that stores 100 cities' weather data
int end = 0; // stores the index value for the first unused element in the array

// function prototypes
void addCity(char time[30], char city[30], char country[30], int temp, int feelsTemp, int minTemp, int maxTemp, int wind, int percipitation);
int getCityIndex(char city[30]);

int main()
{
    // some test code to make sure it was working
    char time[30]= "test";
    char city[30]= "test";
    char city2[30] = "test2";
    char city3[30] = "test3";
    char country[30] = "test";
    int temp = 0;
    int feelsTemp = 0;
    int minTemp = 0;
    int maxTemp = 0;
    int wind = 0;
    int percipitation = 0;
    addCity(time, city, country, temp, feelsTemp,minTemp,maxTemp,wind,percipitation);
    addCity(time, city2, country, temp, feelsTemp,minTemp,maxTemp,wind,percipitation);
    addCity(time, city3, country, temp, feelsTemp,minTemp,maxTemp,wind,percipitation);
    for (int i = 0; i < end; i++)
    {
        printf("City: %s Temperature: %d \n" , cities[i]->city, cities[i]->temp);
    }
    return (0);
}

// add a city to end of the array, or update the city if already in the array
void addCity(char time[30], char city[30], char country[30], int temp, int feelsTemp, int minTemp, int maxTemp, int wind, int percipitation)
{
    // create and copy city 
    struct WeatherData* newCity = (struct WeatherData*)malloc(sizeof(struct WeatherData));
    strcpy(newCity->time, time);
	strcpy(newCity->city, city);
	strcpy(newCity->country, country);
	newCity->temp = temp;
    newCity->feelsTemp = feelsTemp;
    newCity->minTemp = minTemp;
    newCity->maxTemp = maxTemp;
    newCity->wind = wind;
    newCity->percipitation = percipitation;

    // check if city in already in the array
    int index = getCityIndex(city);
    // if not in the array at city to end of array
    if (index == -1)
    {
        cities[end] = newCity;
    }
    // otherwise free the memory of the old city in the array, and update it
    else
    {
        free(cities[index]);
        cities[index] = newCity;
    }
    end++;
}

// returns the index value of the city in the array, returns -1 if not found
int getCityIndex(char city[30])
{
    // traverse until the end of array
    for (int i = 0; i < end; i++)
    {
        // for each element compare if city string value is same
        if (strcmp(city,cities[i]->city)==0)
        {
            // return the index value if found
            return i;
        }
    }
    // not found then return -1
    return -1;
}