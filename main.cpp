#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

//AUTOMATIC GRADER 
void print_header(){
     const int fieldwidth1{15};
    const int fieldwidth2{15};
    
    
    std::cout << std::setw(fieldwidth1)<< std::left<< "Student";
    std::cout << std::setw(fieldwidth2)<< std::right<< "Score"<< std::endl;
    std:: cout << std::setw(40) << std::setfill('-')<< " " << std::endl;
    std::cout <<std::setfill(' ');
}


void print_footer(double average){
    std::cout<< std::setw(40)<<std::setfill('-')<< " "<< std::endl;
    std::cout <<std::setfill(' ');
    std::cout<<std::setw(15)<< std::left<< "Class Average"
            << std::setw(15) << std::right << average;
}


void print_student(const std::string &student, int score){
    std::cout<< std::setw(15)<<std::left<< student
            <<std::setw(15)<< std::right<<score<<std::endl;
    
}


int evaluation(const std::string &answer, const std::string &answer_key){
    int score{0};
    for(size_t i=0; i<answer_key.size(); ++i){
        if(answer.at(i) == answer_key.at(i))
            score++;
    }
    return score;
    
}


int main(){
    std::fstream in_file;
    std::string name{};
    std::string answer_key{};
    std::string responses{};
    int present_sum{0};
    double average{0};
    int total_students{0};
    
    
    
    
    in_file.open("../answers.txt");
    if(!in_file){
        std::cerr<<"Error the file cannot be found"<< std::endl;
        return 1;
    }
    
    
    in_file>>answer_key;
    
    print_header();
    
    while(in_file>>name>>responses){
        ++total_students;
        int score = evaluation(responses,answer_key);
        present_sum +=score;
        print_student(name, score);
    }
    
    
    if (total_students != 0)
        average = static_cast<double>(present_sum)/total_students;
        
    
    print_footer(average);
    
    in_file.close();
    
    std::cout<<std::endl;
    
    return 0;
    
}
