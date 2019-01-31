#include <QDebug>

int main(int argc, char *argv[])
{
	qDebug() << std::getenv("PATH");
	return 0;
}