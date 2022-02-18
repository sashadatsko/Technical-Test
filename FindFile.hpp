#pragma once

#include <filesystem>
#include <thread>
#include <condition_variable>
#include <atomic>
#include <vector>
#include <iostream>


void iterate(char* path, char* fileName/*, std::atomic<bool> & workdone, std::condition_variable & cv, std::mutex & m*/);
int goFind(char* filename);
        


 


