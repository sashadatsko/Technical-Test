#pragma once

#include <filesystem>
#include <thread>
#include <condition_variable>
#include <atomic>
#include <chrono>
#include <vector>
#include <iostream>

void iterate(const char* path, const char* fileName, std::atomic<bool> & workdone, std::condition_variable & cv, std::mutex & m);
int goFind(const char* filename);
        


 


