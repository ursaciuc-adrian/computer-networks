#include <string>
#include <dirent.h>
#include <cstring>
#include <sys/stat.h>
#include <sstream>
#include <unistd.h>

static std::string GetFileInfo(std::string path) {
    struct stat buf;

    if (stat(path.c_str(), &buf) == -1) {
        return "Could not open the file.";
    }

    std::stringstream stream;

    stream << "Size: " << buf.st_size << " bytes" << std::endl;
    stream << "Owner: " << buf.st_uid << std::endl;
    stream << "Group: " << buf.st_gid << std::endl;
    stream << "Protection: " << buf.st_mode << std::endl;
    char timeBuffer[80];
    struct tm localTime;

    localtime_r(&buf.st_atime, &localTime);
    strftime(timeBuffer, sizeof timeBuffer, "%a, %d %b %Y %T", &localTime);
    stream << "Last accessed: " << timeBuffer << std::endl;

    localtime_r(&buf.st_mtime, &localTime);
    strftime(timeBuffer, sizeof timeBuffer, "%a, %d %b %Y %T", &localTime);
    stream << "Last modified: " << timeBuffer;

    return stream.str();
}

static std::string FindFile(std::string name, std::string fileToFind)
{
    if(name[name.size() - 1] != '/')
    {
        name = name + "/";
    }

    DIR *directory;
    struct dirent *entry;


    if (!(directory = opendir(name.c_str())))
    {
        return "Could not open " + access(name.c_str(), R_OK);
    }

    while ((entry = readdir(directory)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        if(entry->d_type == DT_DIR)
        {
            std::string path = name + entry->d_name;
            std::string found = FindFile(path, fileToFind);

            if(!found.empty())
            {
                closedir(directory);
                return found;
            }
        }
        else
        {
            if(entry->d_name == fileToFind)
            {
                closedir(directory);
                return name + entry->d_name;
            }
        }
    }

    closedir(directory);
    return "";
}