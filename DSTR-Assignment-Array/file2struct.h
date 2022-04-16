#ifndef FILE2STRUCT_H_INCLUDED
#define FILE2STRUCT_H_INCLUDED

#include <vector>
#include "tutor.h"
#include "subject.h"
#include "center.h"

extern std::string TUTOR_FILE;
extern std::string SUBJECT_FILE;
extern std::string CENTER_FILE;
extern std::vector<Subject> _SUBJECT;
extern std::vector<Center> _CENTER;

/**
 * @brief import data from text file to Tutor vector
 *
 * @param filename specifies the text file's path which will be imported
 *
 * @return a vector object with Tutor data from specified text file
 */
std::vector<Tutor> fileToTutor(std::string filename);

/**
 * @brief import data from text file to Subject vector
 *
 * @param filename specifies the text file's path which will be imported
 *
 * @return a vector object with Subject data from specified text file
 */
std::vector<Subject> fileToSubject(std::string filename);

/**
 * @brief import data from text file to Center vector
 *
 * @param filename specifies the text file's path which will be imported
 *
 * @return a vector object with Center data from specified text file
 */
std::vector<Center> fileToCenter(std::string filename);

/**
 * @brief export Tutor vector object to a text file
 *
 * @note tutorV is passed as reference to avoid copying the whole Tutor vector
 *       object into the function
 *
 * @param tutorV specifies the object to be exported
 * @param filename specifies the text file's path to write to
 */
void tutorToFile(std::vector<Tutor> &tutorV, std::string filename);

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
#endif
