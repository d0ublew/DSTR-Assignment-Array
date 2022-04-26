#ifndef FILE2STRUCT_H_INCLUDED
#define FILE2STRUCT_H_INCLUDED

#include <vector>

#include "admin.h"
#include "authentication.h"
#include "center.h"
#include "student.h"
#include "subject.h"
#include "tutor.h"

extern const std::string TUTOR_FILE;
extern const std::string SUBJECT_FILE;
extern const std::string CENTER_FILE;
extern const std::string ADMIN_FILE;
extern std::vector<Subject> _SUBJECT;
extern std::vector<Center> _CENTER;

/**
 * @brief import data from text file to Tutor vector
 *
 * @param filename specifies the text file's path which will be imported to
 *
 * @return a vector object with Tutor data from specified text file
 */
std::vector<Tutor *> fileToTutor(const std::string filename);

/**
 * @brief import data from text file to Subject vector
 *
 * @param filename specifies the text file's path which will be imported to
 *
 * @return a vector object with Subject data from specified text file
 */
std::vector<Subject> fileToSubject(const std::string filename);

/**
 * @brief import data from text file to Center vector
 *
 * @param filename specifies the text file's path which will be imported to
 *
 * @return a vector object with Center data from specified text file
 */
std::vector<Center> fileToCenter(const std::string filename);

/**
 * @brief export Tutor vector object to a text file
 *
 * @note tutorV is passed as reference to avoid copying the whole Tutor vector
 *       object into the function
 *
 * @param tutorV specifies the object to be exported
 * @param filename specifies the text file's path to write to
 */
void tutorToFile(std::vector<Tutor *> &tutorV, std::string filename);

/**
 * @brief import data from text file to Student vector
 *
 * @param filename specifies the text file's path which will be imported to
 *
 * @return a vector object with Student data from specified text file
 */
std::vector<Student> fileToStudent(std::string filename);

/**
 * @brief export Tutor vector object to a text file
 *
 * @note studentV is passed as reference to avoid copying the whole object into
 *       the function
 *
 * @param studentV specifies the object to be exported
 * @param filename specifies the text file's path to write to
 */
void studentToFile(std::vector<Student> &studentV, std::string filename);

/**
 * @brief import data from text file to Admin vector
 *
 * @param filename specifies the text file's path which will be imported to
 *
 * @return a vector object with Admin data from specified text file
 */
std::vector<Admin> fileToAdmin(std::string filename);

/**
 * @brief export Tutor vector object to a text file
 *
 * @note adminV is passed as reference to avoid copying the whole object into
 *       the function
 *
 * @param adminV specifies the object to be exported
 * @param filename specifies the text file's path to write to
 */
void adminToFile(std::vector<Admin> &adminV, std::string filename);

/**
 * @brief to split string with the specified delimiter
 *
 * @param str specifies the string to be split
 * @param delim specifies the delimiter
 *
 * @return a vector object which contains the string tokens
 */
std::vector<std::string> splitString(std::string str, std::string delim);

/**
 * @brief convert float to string with fixed precision
 *
 * @param f specifies the float value to be converted
 * @param n specifies the precision
 *
 * @return a string representation of the float value with fixed precision
 */
std::string float_to_str_prec(float f, int n = 2);

void initCenter();
void initSubject();
void initTutor();
void initAdmin();

#endif
