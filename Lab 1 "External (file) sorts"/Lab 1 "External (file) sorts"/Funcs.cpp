//
//  Funcs.cpp
//  Lab 1 "External (file) sorts"
//
//  Created by Antony Miroshnichenko on 20.02.2024.
//



#include "Funcs.hpp"



bool createFileWithRandomNumbers (const std::string& fileName, const int numbersCount, const int maxNumberValue) {
    
    srand(time(0));

    std::ofstream fout;
    
    fout.open(fileName);
    
    if (!fout.is_open()) {
        
        return false;
        
    }

    std::default_random_engine generator;
    
    std::uniform_int_distribution<int> distribution(0, maxNumberValue);
    
    generator.seed(time(0));

    for (int i = 0; i < numbersCount; i++)
        
        fout << distribution(generator) << " ";

    fout.close();

    return true;
    
}



bool isFileContainsSortedArray (const std::string& fileName) {
    
    std::ifstream fin;
    
    fin.open(fileName);
    
    if (!fin.is_open()) {
        
        return false;
        
    }

    int curr, prev;
    
    fin >> prev;
    
    while (fin >> curr) {
        
        if (curr < prev) {
            
            fin.close();
            
            return false;
            
        }

        prev = curr;
        
    }

    fin.close();

    return true;
    
}



void split4d (const std::string& fnameIn, const std::string& fnameOut1, const std::string& fnameOut2) {
    
    std::ifstream fin;
    std::ofstream fout1;
    std::ofstream fout2;
    
    int size = 1;

    fin.open(fnameIn, std::ios_base::in);
    fout1.open(fnameOut1, std::ios_base::trunc);
    fout2.open(fnameOut2, std::ios_base::trunc);
    
    if (!fin || !fout1 || !fout2) {
        
        std::cout << std::endl << "Не получилось открыть файл" << std::endl;
        
        return;
        
    }

    
    int x;
    
    fin >> x;
    
    while (!fin.eof()) {
        
        int i = 0;
        
        while (!fin.eof() && i < size) {
            
            fout1 << x << " ";
            fin >> x;
            i++;
            
        }
        
        i = 0;
        
        while (!fin.eof() && i < size) {
            
            fout2 << x << " ";
            fin >> x;
            i++;
            
        }
        
    }

    fin.close();
    fout1.close();
    fout2.close();
    
}



void merge4d (const std::string fnameIn1, const std::string fnameIn2, const std::string fnameOut1, const std::string fnameOut2, int size) {
    
    std::ifstream fin1;
    std::ifstream fin2;
    std::ofstream fout1;
    std::ofstream fout2;


    fin1.open(fnameIn1, std::ios_base::in);
    
    if (!fin1) {
        
        std::cout << "Can't open file: " << fnameIn1 << std::endl;
        return;
        
    }

    
    fin2.open(fnameIn2, std::ios_base::in);
    
    if (!fin2) {
        
        std::cout << "Can't open file: " << fnameIn2 << std::endl;
        return;
        
    }

    
    fout1.open(fnameOut1, std::ios_base::trunc);
    
    if (!fout1) {
        
        std::cout << "Can't open file: " << fnameOut1 << std::endl;
        return;
        
    }

    fout2.open(fnameOut2, std::ios_base::trunc);
    
    if (!fout2) {
        
        std::cout << "Can't open file: " << fnameOut2 << std::endl;
        return;
        
    }

    
    int x, y;
    
    fin1 >> x;
    fin2 >> y;
    
    while (!fin1.eof() && !fin2.eof()) {
        
        int i = 0;
        int j = 0;
        
        while (!fin1.eof() && !fin2.eof() && i < size && j < size) {
            
            if (x < y) {
                
                fout1 << x << " ";
                fin1 >> x;
                i++;
                
            }
            
            else {
                
                fout1 << y << " ";
                fin2 >> y;
                j++;
                
            }
            
        }

        while (!fin1.eof() && i < size) {
            
            fout1 << x << " ";
            fin1 >> x;
            i++;
            
        }

        while (!fin2.eof() && j < size) {
            
            fout1 << y << " ";
            fin2 >> y;
            j++;
            
        }

        i = 0;
        j = 0;

        while (!fin1.eof() && !fin2.eof() && i < size && j < size) {
            
            if (x < y) {
                
                fout2 << x << " ";
                fin1 >> x;
                i++;
                
            }
            
            else {
                
                fout2 << y << " ";
                fin2 >> y;
                j++;
                
            }
            
        }

        while (!fin1.eof() && i < size) {
            
            fout2 << x << " ";
            fin1 >> x;
            i++;
            
        }

        while (!fin2.eof() && j < size) {
            
            fout2 << y << " ";
            fin2 >> y;
            j++;
            
        }
        
    }

    while (!fin1.eof()) {
        
        fout1 << x << " ";
        fin1 >> x;
        
    }

    while (!fin2.eof()) {
        
        fout1 << y << " ";
        fin2 >> y;
        
    }

    fin1.close();
    fin2.close();
    fout1.close();
    fout2.close();

    fout1.open(fnameIn1, std::ios_base::trunc);
    fout2.open(fnameIn2, std::ios_base::trunc);
    fout1.close();
    fout2.close();
    
}



void split4n (const std::string& fnameIn, const std::string& fnameOut1, const std::string& fnameOut2) {
    
    std::ifstream fin;
    std::ofstream fout1;
    std::ofstream fout2;

    fin.open(fnameIn, std::ios_base::in);
    fout1.open(fnameOut1, std::ios_base::trunc);
    fout2.open(fnameOut2, std::ios_base::trunc);
    
    if (!fin || !fout1 || !fout2) {
        
        std::cout << std::endl << "Не получилось открыть файл" << std::endl;
        
        return;
        
    }

    int x, y;
    
    
    fin >> x;
    
    while (!fin.eof()) {
        
        fout1 << x << " ";
        fin >> y;
        
        while (!fin.eof() && x <= y) {
            
            x = y;
            fout1 << x << " ";
            fin >> y;
            
        }
        
        if (!fin.eof()) {
            
            x = y;
            fout2 << x << " ";
            fin >> y;
            
            while (!fin.eof() && x <= y) {
                
                x = y;
                fout2 << x << " ";
                fin >> y;
                
            }
            
        }
        
        x = y;
        
    }

    fin.close();
    fout1.close();
    fout2.close();
    
}



void merge4n (const std::string fnameIn1, const std::string fnameIn2, const std::string fnameOut1, const std::string fnameOut2) {
    
    
    
}



bool check (const std::string& fnameIn1, const std::string& fnameIn2, const std::string& fnameIn3, const std::string& fnameIn4) {
    
    std::ifstream fin;
    
    int count = 0;

    
    fin.open(fnameIn1);
    
    if (fin.peek() == std::ifstream::traits_type::eof())
        
        count++;
    
    fin.close();

    
    fin.open(fnameIn2);
    
    if (fin.peek() == std::ifstream::traits_type::eof())
        
        count++;
    
    fin.close();
    

    fin.open(fnameIn3);
    
    if (fin.peek() == std::ifstream::traits_type::eof())
        
        count++;
    
    fin.close();
    

    fin.open(fnameIn4);
    
    if (fin.peek() == std::ifstream::traits_type::eof())
        
        count++;
    
    fin.close();
    

    if (count == 3)
        
        return true;

    return false;
    
}



void print (const std::string& fileName) {
    
    std::ifstream fin;
    std::ofstream fout;

    fin.open(fileName, std::ios_base::in);
    
    int x;
    
    std::cout << std::endl;
    
    while (fin >> x) {
        
        std::cout << x << " ";
        
    }

    fin.close();
    
}



std::string sorted (const std::string& fname1, const std::string& fname2, const std::string& fname3, const std::string& fname4) {
    
    std::ifstream fin;

    
    fin.open(fname1);
    
    if (!(fin.peek() == std::ifstream::traits_type::eof())) {
        
        fin.close();
        return fname1;
        
    }
    
    fin.close();

    
    fin.open(fname2);
    
    if (!(fin.peek() == std::ifstream::traits_type::eof())) {
        
        fin.close();
        return fname2;
        
    }
    
    fin.close();
    

    fin.open(fname3);
    
    if (!(fin.peek() == std::ifstream::traits_type::eof())) {
        
        fin.close();
        return fname3;
        
    }
    
    fin.close();
    

    fin.open(fname4);
    
    if (!(fin.peek() == std::ifstream::traits_type::eof())) {
        
        fin.close();
        return fname4;
        
    }
    
    fin.close();

    return "A.txt";
    
}



void sortFile (const std::string& fileName, const int p) {
    
    if (p == 0) {
        
        split4d (fileName, "C.txt", "D.txt");
        
        int i = 1;
        
        while (!check(fileName, "B.txt", "C.txt", "D.txt")) {
            
            merge4d ("C.txt", "D.txt", fileName, "B.txt", i);
            i *= 2;
            merge4d (fileName, "B.txt", "C.txt", "D.txt", i);
            i *= 2;
            
        }
        
    }
    
    if (p == 1) {
        
        split4n (fileName, "C.txt", "D.txt");
        
        while (!check(fileName, "B.txt", "C.txt", "D.txt")) {
            
            merge4n ("C.txt", "D.txt", fileName, "B.txt");
            merge4n (fileName, "B.txt", "C.txt", "D.txt");
            
        }
        
    }
    
}



int createAndSortFile (const std::string& fileName, const int  numbersCount, const int maxNumberValue, const int p) {
    
    if (!createFileWithRandomNumbers("A.txt", numbersCount, maxNumberValue))
        
        return -1;

    clock_t start, finish;

    start = clock();

    sortFile(fileName, p);

    finish = clock();
    
    std::cout << std::endl << "Время работы алгоритма: " << (float)(finish - start) / CLOCKS_PER_SEC << " s" << std::endl;;

    if (!isFileContainsSortedArray(fileName))
        
        return -2;

    return 1;
}
