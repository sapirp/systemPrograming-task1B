#include "PhoneticFinder.hpp"
#include <string>
#include <iostream>
#include <regex>

//using namespace std;



namespace phonetic{
    std::string find(std::string text,std::string word){ 
     // check if the word is empty
     if(word.empty()) throw std::exception();

    //build the word path for the regex expretion. m
      std::string r_word="(";
      for(auto cw : word){
          if (cw=='w' || cw=='v' || cw=='W' || cw=='V') r_word= r_word+ "[wWvV]";
          else if(cw=='b' || cw=='f' || cw=='p' || cw=='B' || cw=='F' || cw=='P' ) r_word= r_word+ "[bBfFpP]";
          else if(cw=='g' || cw=='j' || cw=='J' || cw=='G') r_word= r_word+ "[jJgG]";
          else if(cw=='c' || cw=='k' || cw=='q' || cw=='C' || cw=='K' || cw=='Q') r_word=r_word+ "[cCkKqQ]";
          else if(cw=='s' || cw=='z' || cw=='S' || cw=='Z') r_word=r_word+ "[sSzZ]";
          else if(cw=='d' || cw=='t' || cw=='D' || cw=='T') r_word=r_word+ "[dDtT]";
          else if(cw=='o' || cw=='u' || cw=='O' || cw=='U') r_word=r_word+ "[oOuU]";
          else if(cw=='i' || cw=='y' || cw=='I' || cw=='Y') r_word=r_word+ "[iIyY]";
          else if(cw=='a' || cw=='A')r_word=r_word+ "[aA]";
          else if(cw=='e' || cw=='E')r_word=r_word+ "[eE]";
          else if(cw=='h' || cw=='H')r_word=r_word+ "[hH]";
          else if(cw=='l' || cw=='L')r_word=r_word+ "[lL]";
          else if(cw=='m' || cw=='M')r_word=r_word+ "[mM]";
          else if(cw=='n' || cw=='N')r_word=r_word+ "[nN]";
          else if(cw=='r' || cw=='R')r_word=r_word+ "[rR]";
          else r_word=r_word+ "[xX]";
      }
      r_word=r_word+ ")";

      //std::cout<<word<<"->"<<r_word<<std::endl;
      std::regex pat(r_word);
    
      std::smatch result;
       
      if (regex_search(text,result,pat)==false) throw std::exception(); //the word dose not exist
      else return result.str(0);   //return the word in the text.
 }    
}