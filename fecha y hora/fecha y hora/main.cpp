//
//  main.cpp
//  fecha y hora
//
//  Created by Luis Navarrete on 04/06/21.
//
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;


int main() {
    
    time_t current_time;
    time_t current_date;
    struct tm * time_info;
    struct tm date_info;
    char timeString[10];
    char dateString[12];
    
    time(&current_time);
    time(&current_date);
    
    time_info = localtime(&current_time);
    date_info = * localtime(&current_time);
    
    strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
    strftime(dateString, sizeof(dateString), "%d/%m/%Y", &date_info);
    
    cout<<endl<<dateString;
    cout<<endl<<timeString;

}
