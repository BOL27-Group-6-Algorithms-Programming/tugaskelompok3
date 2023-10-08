#include <stdio.h>
#include <string.h>

struct Employee
{
    char name[50];
    long int nip;
    char address[100];
    char phoneNum[20];
    char position[20];
    char degree[5];
    float salary;
    int overTime;
    float overTimeSalary;
};

int main()
{
    printf("=========================================\n");
    printf("      Program Penghitungan Gaji\n");
    printf("=========================================\n");

    struct Employee employee;

    printf("Masukkan Nama Anda: ");
    scanf(" %[^\n]", &employee.name);
    printf("Masukkan NIP Anda: ");
    scanf("%ld", &employee.nip);

    printf("Masukkan Alamat Anda: ");
    scanf(" %[^\n]", &employee.address);
    printf("Masukkan Nomor Handphone Anda: ");
    scanf(" %s", &employee.phoneNum);

    printf("Masukkan Jabatan Anda: ");
    scanf(" %[^\n]", &employee.position);
    printf("Masukkan Golongan Anda: ");
    scanf(" %s", &employee.degree);

    if (strcmp(employee.degree, "D1") == 0 || strcmp(employee.degree, "d1") == 0)
    {
        employee.salary = 2500000;
        employee.overTimeSalary = 10000;
    }
    else if (strcmp(employee.degree, "D2") == 0 || strcmp(employee.degree, "d2") == 0)
    {
        employee.salary = 2000000;
        employee.overTimeSalary = 5000;
    }
    else if (strcmp(employee.degree, "D3") == 0 || strcmp(employee.degree, "d3") == 0)
    {
        employee.salary = 1500000;
        employee.overTimeSalary = 2500;
    }

    printf("--------------------------------------------------\n");

    printf("\nNIP              : %ld\n", employee.nip);
    printf("Nama             : %s\n", employee.name);
    printf("Alamat           : %s\n", employee.address);
    printf("No HP            : %s\n", employee.phoneNum);
    printf("Jabatan          : %s\n", employee.position);
    printf("Golongan         : %s\n", employee.degree);
    printf("Gaji Pokok       : Rp.%.2f\n", employee.salary);

    printf("--------------------------------------------------\n");

    printf("Masukkan NIP     : ");
    scanf("%ld", &employee.nip);
    printf("Masukkan Golongan: ");
    scanf(" %s", &employee.degree);
    printf("Masukkan Jam Lembur (DALAM JAM): ");
    scanf("%d", &employee.overTime);
    employee.overTimeSalary = employee.overTimeSalary * employee.overTime;

    printf("--------------------------------------------------\n");
    printf("Total Gaji Bulan Ini: Rp.%.2f\n", employee.salary + employee.overTimeSalary);

    return 0;
}