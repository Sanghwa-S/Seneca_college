/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS02_LAB
Date: 2021/01/27

----------------------------------------------
---------------------------------------------- */

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
    // TODO: Declare read prototypes
	bool read(char* m_name);
	bool read(int& m_empNo);
	bool read(double& m_salary);
}
#endif // !SDDS_FILE_H_
