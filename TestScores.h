/* 
 * File:   TestScores.h
 * Author: D
 *
 * Created on November 23, 2013, 2:34 PM
 */

#ifndef TESTSCORES_H
#define	TESTSCORES_H

class TestScores {
private:
    int numScors;
    int *testScrs;
    float scoreAvg;

public:
    //error class
    class Error
    {};
    //default constructor
    TestScores()
    {
        numScors = 0;
        testScrs = new int[numScors];
        scoreAvg = 0.0;
    }
    
    void setNumScores(int num)
    {
        numScors = num;
    }

    void setScores(int score, int index);
    
    void setAvg(float avg)
    {
        scoreAvg = avg;
    }
    
    int getNumScores() const
    {
        return numScors;
    }
    
    int getScores(int index) const
    {
        return testScrs[index];
    }
    
    float getAvg()
    {
        return scoreAvg;
    }
    
};


#endif	/* TESTSCORES_H */

