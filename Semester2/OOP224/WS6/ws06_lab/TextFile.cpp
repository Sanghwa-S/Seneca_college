/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS06_LAB
Date: 2021/03/10

----------------------------------------------
---------------------------------------------- */
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"

using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }

   void TextFile::setEmpty()
   {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
       m_noOfLines = 0;
   }

   void TextFile::setFilename(const char* fname, bool isCopy)
   {
       delete[] m_filename;
       if (!isCopy) 
       {
           m_filename = new char[strLen(fname) + 1];
           strCpy(m_filename, fname);
           return;
       }
       m_filename = new char[strLen(fname) + 3];
       string copy_name = "C_";
       for (int i = 0; i < (int)strLen(fname); i++)
       {
           copy_name += fname[i];
       }
       strCpy(m_filename, copy_name.c_str());
   }

   void TextFile::setNoOfLines()
   {
       int count = 0;
       ifstream in;
       in.open(m_filename);
       string line;
       while (getline(in, line))
       {
           count++;
       }
       in.close();
       if (!count) 
       {
           delete[] m_filename;
           m_filename = nullptr;
           m_noOfLines = 0;
           return;
       }
       m_noOfLines = count;
   }

   void TextFile::loadText()
   {
       delete[] m_textLines;
       if (m_filename != nullptr) 
       {
           m_textLines = new Line[m_noOfLines];
           ifstream fin;
           fin.open(m_filename);
           if (fin.is_open()) 
           {
               string line;
               for (int i = 0; i < (int)m_noOfLines; i++) 
               {
                   getline(fin, line);
                   m_textLines[i] = line.c_str();
               }
           }
           fin.close();
       }
       return;
   }

   void TextFile::saveAs(const char* fileName) const
   {
       if (fileName != nullptr)
       {
           ofstream out;
           out.open(fileName);
           if (out.is_open())
           {
               for (int i = 0; i < (int)m_noOfLines; i++)
               {
                   out << m_textLines[i] << '\n';
               }
           }
           out.close();
       }
       return;
   }

   TextFile::TextFile(unsigned int pageSize)
   {
       m_pageSize = pageSize;
       m_filename = nullptr;
       m_textLines = nullptr;
       m_noOfLines = 0;
   }

   TextFile::TextFile(const char* filename, unsigned int pageSize)
   {
       m_pageSize = pageSize;
       m_filename = nullptr;
       m_textLines = nullptr;
       m_noOfLines = 0;
       if (filename != nullptr) 
       {
           setFilename(filename);
           setNoOfLines();
           loadText();
       }
   }


   TextFile::TextFile(const TextFile& incomingTextFile)
   {
       m_pageSize = incomingTextFile.m_pageSize;
       m_filename = nullptr;
       m_textLines = nullptr;
       m_noOfLines = 0;
       setFilename(incomingTextFile.m_filename, true);
       incomingTextFile.saveAs(m_filename);
       setNoOfLines();
       loadText();
   }

   TextFile& TextFile::operator=(const TextFile& incomingTextFile)
   {
       if (this != &incomingTextFile)
       {
           delete[] m_textLines;
           m_textLines = nullptr;
           incomingTextFile.saveAs(m_filename);
           setNoOfLines();
           loadText();
       }

       return *this;
   }

   TextFile::~TextFile()
   {
       delete[] m_filename;
       delete[] m_textLines;
   }

   unsigned TextFile::lines() const
   {
       return m_noOfLines;
   }

   std::ostream& TextFile::view(ostream& ostr) const
   {
       if (!*this) return ostr;
       ostr << m_filename << endl;
       for (int i = 0; i < strLen(m_filename); i++)
       {
           ostr << '=';
       }
       ostr << "" << endl;
       for (int i = 0; i < (int)m_noOfLines; i++) 
       {
           if (!(i % m_pageSize) && i) 
           {
               ostr << "Hit ENTER to continue...";
               cin.get();
           }
           ostr << m_textLines[i].m_value << endl;
       }

       return ostr;
   }

   std::istream& TextFile::getFile(istream& istr)
   {
       string filename;
       istr >> filename;
       while (getchar() != '\n');
       setFilename(filename.c_str());
       setNoOfLines();
       loadText();
       return istr;
   }

   const char* TextFile::operator[](unsigned int index) const
   {
       if (m_textLines == nullptr)
       {
           return nullptr;
       }
       return m_textLines[index % m_noOfLines];
   }

   TextFile::operator bool() const
   {
       return !(this->m_textLines == nullptr || this->m_filename == nullptr || !this->m_noOfLines);
   }

   const char* TextFile::name() const
   {
       return m_filename;
   }

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
   {
       text.view(ostr);
       return ostr;
   }

   std::istream& operator>>(std::istream& istr, TextFile& text)
   {
       text.getFile(istr);
       return istr;
   }
}