#include <stdio.h>
#include <string.h>

struct Employee
{
    char name[50];
    long int nip;
    char address[100];
    long int phoneNum;
    char position[20];
    char degree[5];
    float salary;
    int overTime;
    float overTimeSalary;
};
int main()
{
    struct Employee employee;

    printf("Masukan Nama anda: ");
    scanf(" %[^\n]", &employee.name);
    printf("Masukan NIP anda: ");
    scanf("%ld", &employee.nip);

    printf("Masukan Alamat anda: ");
    scanf(" %[^\n]", &employee.address);
    printf("Masukan Nomer Handphone anda: ");
    scanf("%ld", &employee.phoneNum);

    printf("Masukan Jabatan anda: ");
    scanf(" %[^\n]", &employee.position);
    printf("Masukan Golongan anda: ");
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
    printf("\nNIP = %ld\n", employee.nip);
    printf("Nama = %s\n", employee.name);
    printf("Alamat = %s\n", employee.address);
    printf("No HP = %ld\n", employee.phoneNum);
    printf("Jabatan = %s\n", employee.position);
    printf("Golongan = %s\n", employee.degree);
    printf("Gaji = Rp.%.2f\n\n", employee.salary);

    printf("Masukan NIP: ");
    scanf("%ld", &employee.nip);
    printf("Masukan Golongan: ");
    scanf(" %s", &employee.degree);
    printf("Masukan jam lembur (DALAM JAM): ");
    scanf("%d", &employee.overTime);
    employee.overTimeSalary = employee.overTimeSalary * employee.overTime;
    printf("Total gaji bulan ini: Rp.%.2f", employee.salary + employee.overTimeSalary);

    return 0;
}