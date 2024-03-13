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
#include <utility> /* std::pair */
#include <vector>  /* needed for GraphList */

/* my hopefully obnoxiously long enough namespace */
namespace DominicsSelfImplement 
{
    /* Matrix impl of Graphs*/
    template<class T>
    class GraphMatrix
    {
        public:
            /* constructors (destructores)*/
            GraphMatrix();
            ~GraphMatrix();
            
            std::vector<T> getEdges(int index);
            std::pair<int, T> getVert(int index);

            // create matrix from two vectors?

            // add vertex, 
            GraphMatrix addVertex(T data, std::vector<int> edges);
            // add edge
            GraphMatrix addEdge(int index, int edge, int weight = 1);


        private:
            //a 2 array of data holds the weight of edges, where 0 is not an edge
            std::vector<std::vector<int> > _matrix;
            std::vector<std::pair<int, T> > _vertex;
            int _size;


    };
    // std::pair is enough, no need to reinvent the wheel.
    //// matrix verticies
    //template<class T>
    //class m_vert
    //{
    //    public:
    //        /* constructors (destructores)*/
    //        m_vert();
    //        ~m_vert();
    //        
    //    private:
    //        //friends?
    //        T data;
    //        int index;
    //}

    /* list impl of graphs */
    //template<class T>
    //class Graphlist
    //{
    //    public:
    //        /* constructors (destructores)*/
    //        Graphlist();
    //        ~Graphlist();
//
    //    private:
    //        std::vector<int> ;
    //    
    //};
//
    //template<class T>
    //class l_vert
    //{
    //    public:
    //        /* constructors (destructores)*/
    //        l_vert();
    //        ~l_vert();
//
    //    private:
//
    //        T data;
    //        
    //};

}
#include "graph.cpp" // this is because templates are awesome but compllicated
//basically because templates are "patters" not code the implementation and 
//deffinition needs to exist in the same place. This is the more flexible
//solution but its a bit odd.
#endif //clang wants a new line
