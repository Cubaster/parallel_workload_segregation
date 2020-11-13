#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <chrono>
 
struct Record {
    int job;
    int p_j;
    int r_j;
    int size_j;
};

int getInteger(std::string str) {
    std::stringstream ss;
    ss << str;
    int integer;
    std::string temp;
    while(!ss.eof()) {
        ss>>temp;
        if (std::stringstream(temp) >> integer) {
            return integer;
        }
        temp = "";
    }
    return 0;
}

int* read_base(std::string file) {
    int* baseValues = new int[2];
    std::ifstream input(file);
    std::string line;
    while(std::getline(input, line))
    {   
        if(line[0] != ';') break;
        if(line.find("MaxNodes") != -1 || line.find("MaxProcs") != -1) {
            int num = getInteger(line);
            if(num > baseValues[1]) 
                baseValues[1] = num;
        }
       if(line.find("MaxJobs") != -1 || line.find("MaxRecords") != -1) {
            int num = getInteger(line);
            if(num > baseValues[0]) 
                baseValues[0] = num;
        }
    }
    input.close();
    return baseValues;
}


Record getRecord(std::string str) {
    int* tab = new int[4];
    std::stringstream ss;
    ss << str;
    int j=0;
    for(int i=0;i<5;i++)
    {
        ss>>tab[j];
        if(i==2) continue;
        j++;
    }
    Record record = {tab[0], tab[1], tab[2], tab[3]};
    return record;
}

std::vector<Record> getRecords(std::string file, int maxrecords) {
    std::vector<Record> records;
    std::string line;
    std::ifstream input(file);
    while(std::getline(input, line))
        if(line[0] != ';') break;
    for(int i=0; i<maxrecords; i++)
        {
        records.push_back(getRecord(line));
        std::getline(input, line);
        }
    return records;
}

int** grasp(int** records) {
    int current_time = 0;
    int **test;
    do{

    }while(++current_time);
    return test;
}

int main(int argc, char* argv[]) {
    int *baseValues = read_base(argv[1]);
    //std::cout<<"Values: "<<baseValues[0]<<" "<<baseValues[1]<<std::endl;
    std::vector<Record> records = getRecords(argv[1], baseValues[0]);
    for(int i=0; i<baseValues[0]; i++)
        printf("Job#: %d, r_j: %d, p_j: %d, size_j: %d\n", records[i].job, records[i].p_j, records[i].r_j, records[i].size_j);

}