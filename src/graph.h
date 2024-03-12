//---------------------------------------------------------------------------
#ifndef GRAPHS_H
#define GRAPHS_H
//---------------------------------------------------------------------------

/*!****************************************************************************\

  \file   graph.h
  \author Dominic Severe
  \date   3-9-2024

  \par            email:  dominicsevere\@gmail.edu
  \par          project:  SolveMate

  \brief
      deffinition of self implimented Graphs, matrix and list.
  
      Functions include:
  
         +
  
    Cohesive Responsibility:
      defines Graphs
  
    Notable portions:
       

\******************************************************************************/
/**********************************************************\
 *    Includes 
\**********************************************************/
#include <vector>  /* needed for GraphList*/
#include <utility> /* std::pair */
/* my hopefully obnoxiously long enough namespace*/
namespace DominicsSelfImplement 
{
    /* Matrix impl of Graphs*/
    template<class T>
    class GraphMatrix
    {
        public:
            /* constructors (destructores)*/
            GraphMatrix();
            ~GraphMatrix

            // create matrix from two vectors

            // add vertex
            // add edge


        private:
            //a 2 array of data
            T ** m_vert<T> _matrix;
            int _size
            

    };

    // matrix verticies
    template<class T>
    class m_vert
    {
        public:
            /* constructors (destructores)*/
            m_vert();
            ~m_vert();
            
        private:
            //friends?
            T data;
            int index;
    }

    /* list impl of graphs */
    template<class T>
    class Graphlist
    {
        public:
            /* constructors (destructores)*/
            Graphlist();
            ~Graphlist();

        private:
            std::vector<int> ;
        
    };

    template<class T>
    class l_vert
    {
        public:
            /* constructors (destructores)*/
            l_vert();
            ~l_vert();

        private:

            T data;
            
    };

}
#endif //clang wants a new line
