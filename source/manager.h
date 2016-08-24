#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>

class ManagerOptions
{
public:
    bool readOnly;
};

class Manager
{
private:
    std::vector<std::string> databaseNames;

public:
    static const std::string HttpErrorDomain = "";

    static const std::string Version = "";

    const std::string directory;

    std::string storageType;

    static Manager sharedInstance() const;

    static void enableLogging(std::string type, int level);

    static bool isValidDatabaseName(std::string name) const;

    Manager();

    Manager(std::string directory, ManagerOptions options);

    void close();

    const std::vector<std::string> allDatabaseNames() const;

    Database* getDatabase(std::string name);

    Database* getExistingDatabase(std::string name) const;

    Database* openDatabase(std::string name, DatabaseOptions options);

    bool replaceDatabase(std::string name, std::string databaseFile, std::string attachmentsDirectory);
};

#endif // MANAGER_H
