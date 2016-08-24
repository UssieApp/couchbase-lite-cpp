#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include <map>
#include <functional>

class DatabaseOptions
{
public:
    bool create;

//    EncryptionKey* encryptionKey;

    bool readOnly;

    std::string storageType;

    DatabaseOptions() : create(false), readOnly(false) {}
};

class Database
{
private:
//    std::vector<Replication> replications;
//    std::vector<ChangeDelegate> changeDelegates;

public:

    // see http://en.cppreference.com/w/cpp/utility/functional/function for delegates
//    class ChangeEvent : Event {};

//    typedef ChangeDelegate std::function<Event()>;

//    class ReplicationFilter : Filter {};

//    typedef FilterDelegate std::function<ReplicationFilter()>;

//    class AsyncTask {};

//    typedef RunAsyncDelegate std::function<AsyncTask()>;

//    class TransactionalTask {};

//    typedef RunInTransactionDelegate std::function<TransactionalTask()>;

//    class Validator {};

//    typedef ValidateDelegate std::function<Validator()>;

//    typedef ValidateChangeDelegate std::function<bool(std::string, Object, Object)>;

/*
    class ValidationContext {
        const std::vector<std::string> changedKeys;
        const SavedRevision currentRevision;

        virtual void reject() = 0;
        virtual void reject(std::string message) = 0;
        virtual void validateChanges(ValidateChangeDelegate validateChangeDelegate) = 0;
    };
*/

    static const std::string Change = "";

    const Manager* manager;

    const std::string name;

    int maxRevTreeDepth;

//    std::vector<Replication> allReplications() const;

//    static const CompileFilterDelegate filterCompiler() const;

//    static void filterCompiler(CompileFilterDelegate);

    int documentCount() const;

    long lastSequenceNumber() const;

    Database();

//    void compact();
//    void deleteDatabase();

//    void addChangeListener(ChangeDelegate delegate);
//    bool removeChangeListener(ChangeDelegate delegate);

//    void runAsync(RunAsyncDelegate delegate);

//    bool runInTransaction(RunInTransactionDelegate delegate);

    // set filter
//    void filter(std::string name, FilterDelegate delegate);
    // get filter
//    FilterDelegate* filter(std::string name);

    // set validation
//    void validation(std::string name, ValidateDelegate delegate);
    // get validation
//    ValidateDelegate* validation(std::string name);

    Query createAllDocumentsQuery();

    Document* createDocument();
    Document* getDocument(std::string id);
    Document* getExistingDocument(std::string id);

//    bool putLocalDocument(std::string id, std::map<std::string, Object> properties);
//    Document* getExistingLocalDocument(std::string id);
//    bool deleteLocalDocument(std::string id);

//    View* getView(std::string name);
//    View* getExisitingView(std::string name);

//    Replication createPullReplication(URL url);

//    Replication createPushReplication(URL url);

};

#endif // DATABASE_H
