#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_size 100
#define seg_day 86400
#define seg_hour 3600
#define seg_min 60

void printime(time_t* mytime, struct tm* pt,char actualdate[]); 
void getusertime(time_t* usertime,struct tm *ptuser,char userdate[]);
void difference(time_t usertime, time_t mytime);