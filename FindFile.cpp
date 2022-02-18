#include "FindFile.hpp"

namespace fs = std::filesystem;

std::vector<std::string> rootDirs;

// std::condition_variable cv;
// std::mutex m;


void iterate(char* path, char* fileName/*, std::atomic<bool> & workdone, std::condition_variable & cv, std::mutex & m*/)
{
    // std::unique_lock<std::mutex> lk(m);

    for (const auto& entry : fs::recursive_directory_iterator(path, fs::directory_options::skip_permission_denied))
    {
        try
        {
            if(fs::exists(entry))
            {
                if(entry.path().filename() == fileName)
                {
                    std::cout << fileName << " found\n";
                    std::cout << "PATH TO FILE: " << entry.path() << "\n\n";
                    // std::notify_all_at_thread_exit(std::ref(cv), std::move(lk));
                }
            }

        }catch(fs::__cxx11::filesystem_error &e)
        {
            //ignore
        }

    }
}

int goFind(char* filename)
{
    fs::path rootPath = fs::current_path();

    if(!rootPath.has_root_directory())
        std::cout << "root directory is empty\n";

    for(const auto &entry : fs::directory_iterator(rootPath.root_directory()))
    {
        if(fs::is_directory(entry.symlink_status()))
            rootDirs.push_back(entry.path());
    }
        

    std::vector<std::thread> threads;

    std::atomic<bool> workdone(false);

    unsigned i = 0;

    bool endOfDirs = false;

    while(i < rootDirs.size())
    {
        for(int j = 0; j < 8; j++, i++)
        {
            if(i == rootDirs.size())
            {
                std::cout << "\nFILE NOT FOUND\n" << std::endl;
                endOfDirs = 1;
                break;
            }

            threads.push_back(std::thread(iterate, &rootDirs[i][0], filename/*, std::ref(workdone), std::ref(cv), std::ref(m)*/));
            threads.back().join();
        }

        if(endOfDirs)
            break;

        i++;
    }


    // int workingThreads = 0;
    // while(i < rootDirs.size())
    // {
    //     for(; workingThreads < 8; workingThreads++, i++)
    //     {
    //         if(i == rootDirs.size())
    //         {
    //             std::cout << "\nFILE NOT FOUND\n\n";
    //             break;
    //         }

    //         threads.push_back(std::thread(iterate, &rootDirs[i][0], filename/*, std::ref(workdone), std::ref(cv), std::ref(m)*/));
    //     }
    

    //     for(int j = 0; j < workingThreads; j++)
    //     {
    //         threads[j].join();
    //     }

    //     workingThreads = 0;

    //     i++;
    // }

    return 0;
}


