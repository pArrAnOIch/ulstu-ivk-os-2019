#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/*
	Лаб.раб. ОС №4.4
	Выполнил: Ахметов Э.Н. ИСТбд-22 
*/
int main()
{
	int fd[2], result;
	size_t size;
	pipe(fd);
	result = fork();
	if (result > 0)
	{//Родительский процесc
		int buf = 0;
		close(fd[0]);//Закрываем поток чтения
		while (1)
		{ // Родитель в бесконечном цикле записывает по 1 байту в поток
			buf++;
			size = write(fd[1],"", 1);
			printf("%d байт \n ", buf); //размер канала в используемой операционной системе
		}

		close(fd[1]);//Закрываем поток записи
	}
	else
	{//Дочерний процесс
		close(fd[1]);//Закрываем поток записи
		while (1); // Потомок ничего не читает из потока
		close(fd[0]);//Закрываем поток чтения
	}
	return 0;
}
