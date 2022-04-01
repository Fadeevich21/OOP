#pragma once

#include <vector>
#include <map>
#include <string>
#include <set>


using namespace std;

namespace StudySchedule_
{
	enum class EnumDayStudyWeek
	{
		monday = 0, tuesday, wednesday, thursday, friday
	};

	enum class EnumStudyLesson
	{
		firstLesson = 0, secondLesson, thirdLesson, fourthLesson, fifthLesson
	};

	struct Subject
	{
	private:
		string name_;

	public:
		Subject(const string &name = "");

		string getName() const;
		void setName(const string &name);

		void readSubject();
		void printSubject() const;

		bool operator==(const Subject &subject) const;
		bool operator<(const Subject &subject) const;
	};

	struct Teacher
	{
	private:
		string name_;
		string surname_;
		string patronymic_;

	public:
		Teacher(const string &name = "", const string &surname = "", const string &patronymic = "");

		string getName() const;
		void setName(const string &name);

		string getSurname() const;
		void setSurname(const string &surname);

		string getPatronymic() const;
		void setPatronymic(const string &patronymic);

		void readInfoTeacher();
		void printInfoTeacher() const;

		bool operator==(const Teacher &teacher) const;
		bool operator<(const Teacher &teacher) const;
	};

	struct StudyTeachers
	{
	private:
		set<Teacher> setOfTeachers_;

	public:
		void addTeacher(const Teacher &teacher);
		void removeTeacher(const Teacher &teacher);

		bool checkFindTeacher(const Teacher &teacher) const;
		Teacher getRandomTeacher();

		void printTeachers() const;
	};

	struct Cabinet
	{
	private:
		string cabinet_;

	public:
		Cabinet(const string &cabinet = "");

		string getCabinet() const;
		void setCabinet(const string &cabinet);

		void readCabinert();
		void printCabinet() const;

		bool operator==(const Cabinet &cabinet) const;
		bool operator<(const Cabinet &cabinet) const;
	};

	struct StudyCabinets
	{
	private:
		set<Cabinet> setOfCabinets_;

	public:
		void addCabinet(const Cabinet &cabinet);
		void removeCabinet(const Cabinet &cabinet);

		bool checkFindCabinet(const Cabinet &cabinet) const;
		Cabinet getRandomCabinet();

		void printCabinets() const;
	};

	struct Ttime
	{
	private:
		size_t hour_;
		size_t minute_;

	public:
		Ttime(const Ttime &ttime);
		Ttime(const size_t &hour, const size_t &minute);

		void setHour(const size_t &hour);
		void setMinute(const size_t &minute);
		void setTtime(const size_t &hour, const size_t &minute);

		size_t getHour() const;
		size_t getMinute() const;
		pair<size_t, size_t> getTtime() const;

		void printTtime() const;
	};

	struct Time
	{
	private:
		Ttime ttime_;

	public:
		Time(const size_t &hour = size_t(), const size_t &minute = size_t());
		
		void setTime(const Ttime &ttime);
		void setTime(const size_t &hour, const size_t &minute);

		Ttime getTime() const;

		void readTime();
		void printTime() const;
	};

	struct Group
	{
	private:
		string name_;
		const multiset<Subject> allSubjectsOfGroup_;
		multiset<Subject> nonUsedSubjectsOfGroup_;

	public:
		Group(const string &name = "", const multiset<Subject> &allSubjectOfGroup = {});

		void setGroup(const string &name);
		string getGroup() const;

		bool checkFindSubject(const Subject &subject) const;
		bool checkFindNonUsedSubject(const Subject &subject) const;

		void addSubject(const Subject &subject);
		void removeSubject(const Subject &subject);

		void readGroup();
		void printGroup() const;

		bool operator==(const Group &group) const;
		bool operator<(const Group &group) const;
	};


	struct InfoAboutLessonGroup
	{
	private:
		Teacher teacher_;
		Cabinet cabinet_;
		Subject subject_;

	public:
		InfoAboutLessonGroup(const Teacher &teacher = Teacher(), const Cabinet &cabinet = Cabinet(), const Subject &subject = Subject());

		void setTeacher(const Teacher &teacher);
		Teacher getTeacher() const;

		void setCabinet(const Cabinet &cabinet);
		Cabinet getCabinet() const;

		void printInfoAboutLessonGroup() const;
	};

	struct StudyLesson
	{
	private:
		Time time_;
		StudyTeachers studyTeachers_;
		StudyCabinets studyCabinets_;

		map<Group, InfoAboutLessonGroup> lessonOfGroupAtThisTime_;

	public:
		StudyLesson(const Time &time, const StudyTeachers &studyTeachers, const StudyCabinets &studyCabinets);

		void addStudyLesson(Group &group, const Teacher &teacher, const Cabinet &cabinet, const Subject &subject);
		void printStudyLesson(const Group &group) const;
	};

	struct StudyDay
	{
	private:
		vector<StudyLesson> vecStudyLessons_;

	public:
		StudyDay(const StudyTeachers &studyTeachers, const StudyCabinets studyCabinets);

		StudyLesson &operator[](const EnumStudyLesson &lesson);
		const StudyLesson &operator[](const EnumStudyLesson &lesson) const;
		size_t size() const;
		void printStudyDay(const Group &group) const;
	};

	struct StudyWeek
	{
	private:
		vector<StudyDay> vecStudyDay_;

	public:
		StudyWeek(const StudyTeachers &studyTeachers, const StudyCabinets studyCabinets);

		StudyDay &operator[](const EnumDayStudyWeek &day);
		const StudyDay &operator[](const EnumDayStudyWeek &day) const;
		size_t size() const;
		void printStudyWeek(const Group &group) const;
	};

	struct StudySchedule
	{
	private:
		const StudyTeachers studyTeachers_;
		const StudyCabinets studyCabinets_;
		const vector<Group> vecGroups_;

		StudyWeek studyWeek_;

	public:
		StudySchedule(const StudyTeachers &studyTeachers, const StudyCabinets &studyCabinets, const vector<Group> &vecGroups);

		void addStudyLessonGroup(Group &group, const EnumDayStudyWeek &day, const EnumStudyLesson &lesson, const Teacher &teacher, const Cabinet &cabinet, const Subject &subject);
		void printStudyShedule() const;
	};

}