#include "mysort.c"
#include "myrecord.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

/*
 * Define a structure named RECORD to hold a person's name of 20 characters and 
 * the score of float type.
*/
typedef struct record{
    float score;
    char name[20];
}RECORD;

/*
 * Define a structure named STATS containing fields: int count, float mean, 
 * loat stddev (standard deviation), and float median.
*/
typedef struct stats{
    int count;
    float mean;
    float stddev;
    float median;
}STATS;

/*
 * Define a structure named GRADE to hold a string letter_grade at most 2 letters. 
*/
typedef struct grade{
    char letter_grade[3];
} GRADE;

/*
 * Convert a percentage grade to letter grade defined by percentage ranges
 * A+=[90, 100], A=[85, 90), A-=[80, 85), B+=[77, 80), B=[73, 77) B=[70, 73),
 * C+=[67, 70), C=[63, 77), C-=[60, 63), D+=[57,60),D=[53,57),D=[50,53), F=[0,50).
 *
 * @param score -  percetage grade.
 *
 * @return - letter grade wrapped in GRADE structure type.
 */
GRADE grade(float score){
    //create an array of strings of all the grades, then the grade ranges
    //binary search for the grade
    GRADE r = {"F"};
    int p  =  (int)round(score);
    char g[14][5] = {"A+", "A ", "A-", "B+", "B ", "B-", "C+", "C ", "C-", "D+","D ","D-","F "};
    int b[] = {100, 90, 85, 80, 77, 73, 70, 67, 63, 60, 57, 53, 50, 0};
    int left =0, right = sizeof(b)/sizeof(float)-1;
    //binary search logic:
    //if the score Im checking for is bounded by b[left] and b[left + 1] then return g[middle][0] and g[middle][1]
    while(left <= right){
        int mid = left + (right - left)/2;
        if(score < b[left] && score >=b[left+1]){
            strcpy(r.letter_grade, g[mid][1]);
        }
        else if(b[mid] < score && !(score < b[left] && score >=b[left+1])){
            left = mid + 1;
        }
        else if(b[mid] > score && !(score < b[left] && score >=b[left+1])){    
            right = mid -  1;
        }
    return r;
    }
}

/*
 *  Import record data from file and store name and store all record entries
 *  in the RECORD array passed by records, return the number of record count.
 *
 *  @param *fp -  FILE pointer to intput file.
 *  @param dataset - array of RECODR type to store record data.
 *  @return   - number of records
 */
int import_data(FILE *fp, RECORD *dataset){
    int n;
    char delimiters = ",\n\r";
    char line[100];
    char *token = NULL;
    while(fgets(line,sizeof(line),fp)!= NULL){
        if (sscanf(line, "%[^,],%f", dataset[n].name, &dataset[n].score) == 2) {
            n++;
        }
    } 
    return n;
}

/*
 *  Take the RECORD data array as input, compute the average score, standard deviation,
 *  median of the score values of the record data, and returns the STATS type value.
 *
 *  @param dataset -  input record data array.
 *  @param count -  the number of data record in dataset array.
 *  @return  -  stats value in STATS type.
 */
STATS process_data(RECORD *dataset, int count) {
    STATS stats;
    stats.count = count;
    
    if (count < 1) {
        stats.mean = 0.0;
        stats.stddev = 0.0;
        stats.median = 0.0;
        return stats;
    }

    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += dataset[i].score;
    }
    stats.mean = sum / count;

    // Compute standard deviation
    float variance_sum = 0.0;
    for (int i = 0; i < count; i++) {
        variance_sum += pow(dataset[i].score - stats.mean, 2);
    }
    stats.stddev = sqrt(variance_sum / count);

    // Compute median (sort scores first)
    float *scores = (float *)malloc(count * sizeof(float));
    for (int i = 0; i < count; i++) {
        scores[i] = dataset[i].score;
    }

    // Sort scores using qsort
    qsort(scores, count, sizeof(float), (int (*)(const void *, const void *))cmp);

    // Compute median
    if (count % 2 == 1) {
        stats.median = scores[count / 2];
    } else {
        stats.median = (scores[count / 2 - 1] + scores[count / 2]) / 2.0;
    }

    free(scores);
    return stats;
}


/*
 *  This function takes output file named outfilename, RECORD array records, 
 *  and stats as inputs, prepare and write report of stats and grade to files.
 *  The records in report file are sorted in decreasing of scores.  
 *
 *  @param *fp -  FILE pointer to output file.
 *  @param *dataset - pointer to dataset array.
 *  @param count - the number of data record in dataset array.
 *  @return - returns 1 if successful; 0 if count < 1
 */
int report_data(FILE *fp, RECORD *dataset, STATS stats) {
    if (stats.count < 1) return 0; // No data to report

    // Write statistics
    fprintf(fp, "Number of Records: %d\n", stats.count);
    fprintf(fp, "Mean Score: %.2f\n", stats.mean);
    fprintf(fp, "Standard Deviation: %.2f\n", stats.stddev);
    fprintf(fp, "Median Score: %.2f\n\n", stats.median);

    // Write header for student records
    fprintf(fp, "%-20s %-10s %-5s\n", "Name", "Score", "Grade");
    fprintf(fp, "------------------------------------\n");

    // Write each student's details
    for (int i = 0; i < stats.count; i++) {
        GRADE g = grade(dataset[i].score);
        fprintf(fp, "%-20s %-10.2f %-5s\n", dataset[i].name, dataset[i].score, g.letter_grade);
    }

    return 1; // Success
}
