#ifndef TIME_H
#define TIME_H

class Time
{
private: //Membros Privados
    /* data */
    int hour;
    int minute;
    int second;
public: //Membros Publicos
    Time(int hour = 0, int minute = 0, int second = 0);
    int getHour() const;
    void setHour(int hour);
    int getMinute() const;
    void setMinute(int minute);
    int getSecond() const;
    void setSecond(int second);
    void print() const;
    void nextSecond();
};

#endif //Final Bloco