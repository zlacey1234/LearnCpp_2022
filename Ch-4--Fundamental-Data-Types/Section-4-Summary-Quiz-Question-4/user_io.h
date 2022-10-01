#ifndef USER_IO_H_
#define USER_IO_H_

double GetInitialHeight();
double CalculateBallHeight(double initial_height_meters, int x_seconds);
void PrintHeight(double height_meters, int x_seconds);
void CalculateAndPrintHeight(double initial_height_meters, int x_seconds);

#endif // USER_IO_H_