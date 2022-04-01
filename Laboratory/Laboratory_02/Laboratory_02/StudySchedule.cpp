#include "StudySchedule.hpp"
#include <iostream>
#include <random>

using namespace std;

namespace StudySchedule_
{

	Subject::Subject(const string &name)
	{
		this->name_ = name;
	}

	string Subject::getName() const
	{
		return this->name_;
	}

	void Subject::setName(const string &name)
	{
		this->name_ = name;
	}

	void Subject::readSubject()
	{
		cout << "Введите название предмета: ";

		string name;
		cin >> name;
		setName(name);
	}

	void Subject::printSubject() const
	{
		cout << "Данные о предмете:\n";
		cout << "Название: " << getName() << "\n";

		cout << "\n";
	}

	bool Subject::operator==(const Subject &subject) const
	{
		return this->getName() == subject.getName();
	}

	bool Subject::operator<(const Subject &subject) const
	{
		return this->getName() < subject.getName();
	}

	Group::Group(const string &name, const multiset<Subject> &allSubjectOfGroup) :
		name_(name), allSubjectsOfGroup_(allSubjectOfGroup), nonUsedSubjectsOfGroup_(allSubjectOfGroup)
	{
	}

	void Group::setGroup(const string &name)
	{
		this->name_ = name;
	}

	string Group::getGroup() const
	{
		return this->name_;
	}

	bool Group::checkFindSubject(const Subject &subject) const
	{
		return this->allSubjectsOfGroup_.find(subject) != end(this->allSubjectsOfGroup_);
	}

	bool Group::checkFindNonUsedSubject(const Subject &subject) const
	{
		return this->nonUsedSubjectsOfGroup_.find(subject) != end(this->nonUsedSubjectsOfGroup_);
	}

	void Group::addSubject(const Subject &subject)
	{
		this->nonUsedSubjectsOfGroup_.insert(subject);
	}

	void Group::removeSubject(const Subject &subject)
	{
		this->nonUsedSubjectsOfGroup_.erase(subject);
	}

	void Group::readGroup()
	{
		cout << "Введите название группы: ";

		string name;
		cin >> name;
		setGroup(name);
	}

	void Group::printGroup() const
	{
		cout << "Данные о группе:\n";
		cout << "Название: " << getGroup() << "\n";
		
		cout << "\n";
	}

	bool Group::operator==(const Group &group) const
	{
		return this->getGroup() == group.getGroup();
	}

	bool Group::operator<(const Group &group) const
	{
		return this->getGroup() < group.getGroup();
	}

	Teacher::Teacher(const string &name, const string &surname, const string &patronymic)
	{
		this->setName(name);
		this->setSurname(surname);
		this->setPatronymic(patronymic);
	}

	string Teacher::getName() const
	{
		return this->name_;
	}

	void Teacher::setName(const string &name)
	{
		this->name_ = name;
	}

	string Teacher::getSurname() const
	{
		return this->surname_;
	}

	void Teacher::setSurname(const string &surname)
	{
		this->surname_ = surname;
	}

	string Teacher::getPatronymic() const
	{
		return this->patronymic_;
	}

	void Teacher::setPatronymic(const string &patronymic)
	{
		this->patronymic_ = patronymic;
	}

	void Teacher::readInfoTeacher()
	{
		cout << "Введите данные о преподавателе:\n";
		cout << "Имя: ";
		string readStr;
		cin >> readStr;
		setName(readStr);

		cout << "Фамилия: ";
		setSurname(readStr);

		cout << "Отчество: ";
		setPatronymic(readStr);
	}

	void Teacher::printInfoTeacher() const
	{
		cout << "Данные о преподавателе:\n";
		cout << "Имя: " << getName() << "\n";
		cout << "Фамилия: " << getSurname() << "\n";
		cout << "Отчество: " << getPatronymic() << "\n";

		cout << "\n";
	}

	bool Teacher::operator==(const Teacher &teacher) const
	{
		return this->getName() == teacher.getName() &&
			this->getSurname() == teacher.getSurname() &&
			this->getPatronymic() == teacher.getPatronymic();
	}

	bool Teacher::operator<(const Teacher &teacher) const
	{
		return this->getName() < teacher.getName() ||
			this->getSurname() < teacher.getSurname() ||
			this->getPatronymic() < teacher.getPatronymic();
	}

	Cabinet::Cabinet(const string &cabinet)
	{
		this->setCabinet(cabinet);
	}

	string Cabinet::getCabinet() const
	{
		return this->cabinet_;
	}


	void Cabinet::setCabinet(const string &cabinet)
	{
		this->cabinet_ = cabinet;
	}

	void Cabinet::readCabinert()
	{
		cout << "Введите данные о кабинете:\n";
		cout << "Название: ";
		string readStr;
		cin >> readStr;
		setCabinet(readStr);
	}

	void Cabinet::printCabinet() const
	{
		cout << "Данные о кабинете:\n";
		cout << "Название: " << getCabinet() << "\n";

		cout << "\n";
	}

	bool Cabinet::operator==(const Cabinet &cabinet) const
	{
		return this->getCabinet() == cabinet.getCabinet();
	}

	bool Cabinet::operator<(const Cabinet &cabinet) const
	{
		return this->getCabinet() < cabinet.getCabinet();
	}

	Ttime::Ttime(const Ttime &ttime) : hour_(ttime.getHour()), minute_(ttime.getMinute())
	{
	}

	Ttime::Ttime(const size_t &hour, const size_t &minute) : hour_(hour), minute_(minute)
	{
	}

	void Ttime::setHour(const size_t &hour)
	{
		this->hour_ = hour;
	}

	void Ttime::setMinute(const size_t &minute)
	{
		this->minute_ = minute;
	}

	void Ttime::setTtime(const size_t &hour, const size_t &minute)
	{
		setHour(hour);
		setMinute(minute);
	}

	size_t Ttime::getHour() const
	{
		return this->hour_;
	}

	size_t Ttime::getMinute() const
	{
		return this->minute_;
	}

	pair<size_t, size_t> Ttime::getTtime() const
	{
		return pair<size_t, size_t>(getHour(), getMinute());
	}

	void Ttime::printTtime() const
	{
		cout << "Данные о внутреннем времени:\n";
		cout << "Часов: " << getHour() << "\n";
		cout << "Минут: " << getMinute() << "\n";

		cout << "\n";
	}

	Time::Time(const size_t &hour, const size_t &minute) : ttime_(Ttime(hour, minute))
	{
	}

	void Time::setTime(const Ttime &ttime)
	{
		this->ttime_ = ttime;
	}

	void Time::setTime(const size_t &hour, const size_t &minute)
	{
		this->ttime_ = Ttime(hour, minute);
	}

	Ttime Time::getTime() const
	{
		return this->ttime_;
	}

	void Time::readTime()
	{
		cout << "Введите данные о внешнем времени:\n";
		cout << "Часы: ";

		pair<size_t, size_t> pairElTime;
		cin >> pairElTime.first;

		cout << "Минуты: ";
		cin >> pairElTime.second;

		this->ttime_ = Ttime(pairElTime.first, pairElTime.second);
	}

	void Time::printTime() const
	{
		cout << "Данные о внешнем времени:\n";
		this->ttime_.printTtime();
	}

	void StudyTeachers::addTeacher(const Teacher &teacher)
	{
		this->setOfTeachers_.insert(teacher);
	}

	void StudyTeachers::removeTeacher(const Teacher &teacher)
	{
		this->setOfTeachers_.erase(teacher);
	}

	bool StudyTeachers::checkFindTeacher(const Teacher &teacher) const
	{
		bool check = false;
		for (const auto &el : this->setOfTeachers_)
		{
			check = el == teacher;
			if (check)
			{
				break;
			}
		}

		return check;
	}

	Teacher StudyTeachers::getRandomTeacher()
	{
		size_t indexEl = rand() % this->setOfTeachers_.size();
		auto pos = next(begin(this->setOfTeachers_), indexEl);
		Teacher teacher = *pos;

		return teacher;
	}

	void StudyTeachers::printTeachers() const
	{
		for (const auto &el : this->setOfTeachers_)
		{
			el.printInfoTeacher();
		}
	}

	void StudyCabinets::addCabinet(const Cabinet &cabinet)
	{
		this->setOfCabinets_.insert(cabinet);
	}

	void StudyCabinets::removeCabinet(const Cabinet &cabinet)
	{
		this->setOfCabinets_.erase(cabinet);
	}

	bool StudyCabinets::checkFindCabinet(const Cabinet &cabinet) const
	{
		bool check = false;
		for (const auto &el : this->setOfCabinets_)
		{
			check = el == cabinet;
			if (check)
			{
				break;
			}
		}

		return check;
	}

	Cabinet StudyCabinets::getRandomCabinet()
	{
		size_t indexEl = rand() % this->setOfCabinets_.size();
		auto pos = next(begin(this->setOfCabinets_), indexEl);
		Cabinet cabinet = *pos;

		return cabinet;
	}

	void StudyCabinets::printCabinets() const
	{
		for (const auto &el : this->setOfCabinets_)
		{
			el.printCabinet();
		}
	}

	InfoAboutLessonGroup::InfoAboutLessonGroup(const Teacher &teacher, const Cabinet &cabinet, const Subject &subject) :
		teacher_(teacher), cabinet_(cabinet), subject_(subject)
	{
	}

	void InfoAboutLessonGroup::setTeacher(const Teacher &teacher)
	{
		this->teacher_ = teacher;
	}

	Teacher InfoAboutLessonGroup::getTeacher() const
	{
		return this->teacher_;
	}

	void InfoAboutLessonGroup::setCabinet(const Cabinet &cabinet)
	{
		this->cabinet_ = cabinet;
	}

	Cabinet InfoAboutLessonGroup::getCabinet() const
	{
		return this->cabinet_;
	}

	void InfoAboutLessonGroup::printInfoAboutLessonGroup() const
	{
		cout << "Данные об данных уроке группы:\n";
		this->getTeacher().printInfoTeacher();
		this->getCabinet().printCabinet();
	}

	StudyLesson::StudyLesson(const Time &time, const StudyTeachers &studyTeachers, const StudyCabinets &studyCabinets) :
		time_(time), studyTeachers_(studyTeachers), studyCabinets_(studyCabinets)
	{
	}

	void StudyLesson::addStudyLesson(Group &group, const Teacher &teacher, const Cabinet &cabinet, const Subject &subject)
	{
		if (this->lessonOfGroupAtThisTime_.find(group) != end(this->lessonOfGroupAtThisTime_) ||
			!this->studyTeachers_.checkFindTeacher(teacher) ||
			!this->studyCabinets_.checkFindCabinet(cabinet))
		{
			cout << "В данное время уже есть урок у данной группы\n";
			cout << "Либо у данного преподавателя уже есть пара\n";
			cout << "Либо в данном кабинете уже есть пара\n";
			cout << "\n";
		}
		else
		{
			this->lessonOfGroupAtThisTime_[group] = InfoAboutLessonGroup(teacher, cabinet, subject);
			this->studyTeachers_.removeTeacher(teacher);
			this->studyCabinets_.removeCabinet(cabinet);
			group.removeSubject(subject);
		}
	}

	void StudyLesson::printStudyLesson(const Group &group) const
	{
		cout << "Данные об учебном уроке:\n";
		for (const auto &[k, v] : this->lessonOfGroupAtThisTime_)
		{
			if (k == group)
			{
				v.printInfoAboutLessonGroup();

				cout << "\n";
				break;
			}
		}

		cout << "\n";
	}

	StudyDay::StudyDay(const StudyTeachers &studyTeachers, const StudyCabinets studyCabinets) :
		vecStudyLessons_
	{
		{StudyLesson(Time(8, 15), studyTeachers, studyCabinets)},
		{StudyLesson(Time(10, 00), studyTeachers, studyCabinets)},
		{StudyLesson(Time(11, 45), studyTeachers, studyCabinets)},
		{StudyLesson(Time(14, 20), studyTeachers, studyCabinets)},
		{StudyLesson(Time(16, 05), studyTeachers, studyCabinets)},
		{StudyLesson(Time(17, 50), studyTeachers, studyCabinets)}
	}
	{
	}

	StudyLesson &StudyDay::operator[](const EnumStudyLesson &lesson)
	{
		return this->vecStudyLessons_[static_cast<size_t>(lesson)];
	}

	const StudyLesson &StudyDay::operator[](const EnumStudyLesson &lesson) const
	{
		return this->vecStudyLessons_[static_cast<size_t>(lesson)];
	}

	size_t StudyDay::size() const
	{
		return this->vecStudyLessons_.size();
	}

	void StudyDay::printStudyDay(const Group &group) const
	{
		cout << "Данные об учебном дне:\n";
		int numLesson = int(1);
		for (const auto &el : this->vecStudyLessons_)
		{
			cout << "Урок " << numLesson++ << "\n";
			el.printStudyLesson(group);

			cout << "\n";
		}
	}

	StudyWeek::StudyWeek(const StudyTeachers &studyTeachers, const StudyCabinets studyCabinets)
	{
		for (size_t indexDay = 1; indexDay <= 5; indexDay++)
		{
			this->vecStudyDay_.push_back(StudyDay(studyTeachers, studyCabinets));
		}
	}

	StudyDay &StudyWeek::operator[](const EnumDayStudyWeek &day)
	{
		return this->vecStudyDay_[static_cast<size_t>(day)];
	}

	const StudyDay &StudyWeek::operator[](const EnumDayStudyWeek &day) const 
	{
		return this->vecStudyDay_[static_cast<size_t>(day)];
	}

	size_t StudyWeek::size() const
	{
		return this->vecStudyDay_.size();
	}

	void StudyWeek::printStudyWeek(const Group &group) const
	{
		cout << "Данные об учебной неделе\n";
		int numDay = int(1);
		for (const auto &el : this->vecStudyDay_)
		{
			cout << "День " << numDay++ << "\n";
			el.printStudyDay(group);

			cout << "\n";
		}
	}

	StudySchedule::StudySchedule(const StudyTeachers &studyTeachers, const StudyCabinets &studyCabinets, const vector<Group> &vecGroups) :
		studyTeachers_(studyTeachers), studyCabinets_(studyCabinets), vecGroups_(vecGroups), studyWeek_(studyTeachers, studyCabinets)
	{
	}

	void StudySchedule::addStudyLessonGroup(Group &group, const EnumDayStudyWeek &day, const EnumStudyLesson &lesson, const Teacher &teacher, const Cabinet &cabinet, const Subject &subject)
	{
		if (find(begin(this->vecGroups_), end(this->vecGroups_), group) != end(this->vecGroups_) &&
			this->studyTeachers_.checkFindTeacher(teacher) &&
			this->studyCabinets_.checkFindCabinet(cabinet) &&
			group.checkFindNonUsedSubject(subject))
		{
			this->studyWeek_[day][lesson].addStudyLesson(group, teacher, cabinet, subject);
		}
		else
		{
			cout << "Не существует данной группы, данного преподавателя или данного предмета\n\n";
		}
	}

	void StudySchedule::printStudyShedule() const
	{
		cout << "Данные об учебном расписании:\n";
		for (const auto &el : this->vecGroups_)
		{
			el.printGroup();
			this->studyWeek_.printStudyWeek(el);

			cout << "\n";
		}
	}

}