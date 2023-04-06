#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define path_to_fille "/Users/wedlec/Documents/TestC/TestC/persons.bin"



//структура
typedef struct {
 
int height;
int massa;

    
}Person;
//



//функция вывода отдельной структуры
void print_person(Person person) {
printf("height: %d, massa: %d\n", person.height, person.massa);
}
//




//сохраняем эдеметы в файл
void save_to_file(char* path,Person* person, int count) {
FILE* fout = fopen(path, "wb"); //write_besopasno))))
if (fout == NULL) {
perror("ERROR open file to SAVE");
return;
}

fwrite(person, sizeof(Person), count, fout); // это ф-я удобно записывает в файл .bin

fclose(fout);
}
//



//структура для чтения с файла || ( ф-я типа Person* c параметром  )
Person* read_from_file(char* path) {
    
   Person* out = NULL;  // внутреняя структура для поэтапного заолнения внешней

FILE* fin = fopen(path, "rb");
if (fin == NULL) {
perror("ERROR open file to READ");
return out; //если ош то внежняя структура == внутреней == NULL
}

// для получения размера файла
struct stat st;
stat(path, &st);
//
out = (Person*)malloc(st.st_size); // выдкляем память для внутренй структуры
//

unsigned long long int count = st.st_size / sizeof(Person); //колличество структур в файле

    //структура ,размер её,ко-во,файл
fread(out, sizeof(Person), count, fin); //умное чтение

    
fclose(fin);

return out;//внешняя структура == внутреней
}
//








int main () {
    
int person_count = 2; //ко-во  элем структур
    
Person* persons = NULL; //зануляем ето сама структура
    
    
persons = (Person*)malloc(person_count*sizeof( Person)); //динамически выделяем память
    
    
 /*
for (int i = 0; i < person_count; i++) {
persons[i].height = rand();
persons[i].weight = rand();
}
*/
    
persons[0].height = 190;
persons[0].massa = 164;

persons[1].height = 241;
persons[1].massa = 50;
    
    
save_to_file(path_to_fille, persons, person_count); //сохраняем структурЫ в файл

    
    
    
    
  //ето структура в которую мы записываем ( Person* = Person* )
Person *from_disk = read_from_file(path_to_fille);
//print_person(from_disk[8]);

    for(int i=0; i<person_count; i++){
        
        printf("%d)",i);
        print_person(from_disk[i]);
        
    }
    
    
    
return 0;
}





