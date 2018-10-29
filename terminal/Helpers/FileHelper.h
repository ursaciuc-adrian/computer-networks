#include <string>
#include <dirent.h>
#include <cstring>
#include <sys/stat.h>

static std::string GetFileInfo(std::string path)
{
    struct stat *stats = nullptr;
    if(stat(path.c_str(), stats))
    {
        return "da";
    }

    return "Could not get any stats.";
}
static int total;
static std::string FindFile(std::string name, std::string fileToFind)
{
    DIR *directory;
    struct dirent *entry;

    if (!(directory = opendir(name.c_str())))
    {
        return "Could not open " + name;
    }

    while ((entry = readdir(directory)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        if(entry->d_type == DT_DIR)
        {
            std::string path = name + "/" + entry->d_name;
            total++;

            std::string found = FindFile(path, fileToFind);
            if(!found.empty())
            {
                closedir(directory);
                return found;
            }
        }
        else
        {
            total++;
            if(entry->d_name == fileToFind)
            {
                closedir(directory);
                return name + "/" + entry->d_name;
            }
        }
    }

    closedir(directory);
    return "";
}