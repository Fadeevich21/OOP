#include <iostream>
#include <Windows.h>
#include "StudySchedule.hpp"
#include <vector>

using namespace std;
using namespace StudySchedule_;

int main()
{
	srand(time(nullptr));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "������, ���!" << endl;

	StudyTeachers studyTeachers;
	studyTeachers.addTeacher(Teacher("����", "������", ""));
	studyTeachers.addTeacher(Teacher("�����", "������", ""));
	StudyCabinets studyCabinets;
	studyCabinets.addCabinet(Cabinet("402"));
	studyCabinets.addCabinet(Cabinet("401"));
	multiset<Subject> subjectOfGroup = {Subject("����������"), Subject("��������"), Subject("�������")};
	
	vector<Group> vecGroup = {Group("��-201", subjectOfGroup), Group("��-202", subjectOfGroup), Group("��-201", subjectOfGroup)};

	StudySchedule studySchedule(studyTeachers, studyCabinets, vecGroup);

	studySchedule.addStudyLessonGroup(vecGroup[2], EnumDayStudyWeek::monday, EnumStudyLesson::firstLesson, studyTeachers.getRandomTeacher(), studyCabinets.getRandomCabinet(), *begin(subjectOfGroup));
	studySchedule.addStudyLessonGroup(vecGroup[0], EnumDayStudyWeek::monday, EnumStudyLesson::firstLesson, studyTeachers.getRandomTeacher(), studyCabinets.getRandomCabinet(), *begin(subjectOfGroup));
	studySchedule.addStudyLessonGroup(vecGroup[1], EnumDayStudyWeek::monday, EnumStudyLesson::firstLesson, studyTeachers.getRandomTeacher(), studyCabinets.getRandomCabinet(), *begin(subjectOfGroup));
	
	studySchedule.printStudyShedule();
	
	return 0;
}