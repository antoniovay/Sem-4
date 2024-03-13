//
//  Funcs.cpp
//  Lab 1 "External (file) sorts"
//
//  Created by Antony Miroshnichenko on 20.02.2024.
//



#include "Funcs.hpp"



bool isFileContainsSortedArray(const std::string &fileName) {
    
    std::ifstream origin(fileName, std::ios_base::in);
    
    if (!origin.is_open()) {
        
        std::cerr << "isFileContainsSortedArray: can't open file named: " << fileName << ". . ." << std::endl;
        
        return false;
        
    }
    
    int current = 0, next = 0;
    
    while (origin >> current) {
        
        origin >> next;
        
        if (next < current){
            
            origin.close();
            
            return false;
            
        }
        
    }
    
    origin.close();
    
    return true;
    
}



void scanFile (const char *name) {
    
    FILE *f;
    char s [100];
    
    f = fopen (name, "w");
    printf ("Введите файл F: ");
    fgets (s, 100, stdin);
    fprintf (f, "%s", s);
    fclose (f);
    
}



void printFile (const char *name) {
    
    FILE *f; int x;
    
    f = fopen (name, "r");
    assert(f != NULL);
    
    fscanf (f, "%d", &x);
    
    while (!feof(f)) {
        
        printf ("%d ", x);
        fscanf (f, "%d", &x);
        
    }
    
    fclose (f);
    
}



void split (const char *name, const char *name1, const char *name2) {
    
    FILE *f, *g1, *g2;
    int x, y;

    f = fopen (name, "r");
    g1 = fopen (name1, "w");
    g2 = fopen (name2, "w");
    
    assert(f != NULL || g1 != NULL || g2 != NULL);

    
    fscanf (f, "%d", &x);
    
    while (!feof (f)) {
        
        fprintf (g1, "%d ", x);
        fscanf (f, "%d", &y);
        
        while (!feof (f) && (x <= y)) {
            
            x = y;
            
            fprintf (g1, "%d ", x);
            fscanf (f, "%d", &y);
            
        }
        
        if (!feof (f)) {
            
            x = y;
            
            fprintf (g2, "%d ", x);
            fscanf (f, "%d", &y);
            
            while (!feof (f) && (x <= y)) {
                
                x = y;
                
                fprintf (g2, "%d  ", x);
                fscanf (f, "%d", &y);
                
            }
            
        }
        
        x = y;
        
    }

    fclose (f);
    fclose (g1);
    fclose (g2);
    
}



void merger (const char *name, const char *name1, const char *name2) {
    
    FILE *f, *g1, *g2;
    int x, y, z, k;

    f = fopen (name, "w");
    g1 = fopen (name1, "r");
    g2 = fopen (name2, "r");
    
    assert(f != NULL || g1 != NULL || g2 != NULL);

    fscanf (g1, "%d", &x); 
    fscanf (g2, "%d", &y);
    
    while (!feof (g1) && !feof (g2)) {
        
        if (x < y) {
            
            fprintf (f, "%d ", x);
            fscanf (g1, "%d", &z);
            
            if (!feof (g1) && (x > z)) {
                
                fprintf (f, "%d ", y);
                fscanf (g2, "%d", &k);
                
                while (!feof (g2) && (y <= k)) {
                    
                    y = k;
                    
                    fprintf (f, "%d ", y);
                    fscanf (g2, "%d", &k);
                    
                }
                
                y = k;
                
            }
            
            x = z;
            
        }
        
        else {
            
            fprintf (f, "%d ", y);
            fscanf (g2, "%d", &k);
            
            if (!feof (g2) && y > k) {
                
                fprintf (f, "%d ", x);
                fscanf (g1, "%d", &z);
                
                while (!feof (g1) && (x <= z)) {
                    
                    x = z;
                    
                    fprintf (f, "%d ", x);
                    fscanf (g1, "%d", &z);
                    
                }
                
                x = z;
                
            }
            
            y = k;
            
        }
        
    }
    
    while (!feof (g1)) {
        
        fprintf (f, "%d ", x);
        fscanf (g1, "%d", &x);
        
    }
    
    while (!feof (g2)) {
        
        fprintf (f, "%d ", y);
        fscanf (g2, "%d", &y);
        
    }

    fclose (f); 
    fclose (g1);
    fclose (g2);
    
}



void sort3f(const char *name) {
    
    FILE *g2;
    
    int flag = 0, x;
    
    while (!flag) {
        
        split (name, "001.txt", "002.txt");
        
        g2 = fopen ("002.txt", "r");
        
        if (fscanf (g2, "%d", &x) == EOF) {
            
            fclose (g2);
            flag++;
            
        }
        
        else {
            
            fclose (g2);
            merger (name, "001.txt", "002.txt");
            
        }
        
    }
    
}
