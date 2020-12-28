#ifndef CPU_JOB_H
#define CPU_JOB_H

#include <iostream>

/*
 * CPU_Job holds information for a process to run on the processor
 */
struct CPU_Job {
    int ID;     // process ID
    int length; // process length
    int prior;  // process priority
    CPU_Job(int a = 0, int b = 0, int c = 0) : ID(a), length(b), prior(c) {};
};

/*
 * Operator declarations
 */
bool operator<(const CPU_Job& lhs, const CPU_Job& rhs) {
    if (lhs.prior < rhs.prior) {
        return true;
    }
    else if (lhs.prior > rhs.prior) {
        return false;
    }
    else {
        if (lhs.length < rhs.length) {
            return true;
        }
        else if (lhs.length > rhs.length) {
            return false;
        }
        else {
            if (lhs.ID <= rhs.ID) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}
std::istream& operator>>(std::istream& in, CPU_Job& job) {
    int ID;
    int length;
    int priority;
    if (in >> ID >> length >> priority) {
        job.ID = ID;
        job.length = length;
        job.prior = priority;
    }
    return in;
}
std::ostream& operator<<(std::ostream& out, const CPU_Job& job) {
    out << "Job " << job.ID << " with length " << job.length << " and priority " << job.prior;
    return out;
}

#endif