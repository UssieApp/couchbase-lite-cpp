#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>
#include <map>

#include "revision.h"

typedef PropertyMap std::map<std::String, Object>;

/*
class DocumentChange
{
    const std::string documentId;
    const bool isCOnflict;
    const bool isCurrentRevision;
    const std::string revisionId;
    const URL sourceUrl;
};
*/

class Document
{
private:
//    std::vector<ChangeDelegate> changeListeners;

public:

    static const std::string Change = "";

//    class ChangeEvent {};

//    typedef ChangeDelegate std::function<Event()>;

//    typedef UpdateDelegate std::function<bool(UnsavedRevision)>;

    const std::vector<SavedRevision> conflictingRevisions;

    const std::vector<SavedRevision> leafRevisions;

    const std::vector<SavedRevision> revisionHistory;

    const SavedRevision currentRevision;

//    const std::string currentRevisionId;

    const Database* database;

    const bool deleted;

    const std::string id;

    const PropertyMap properties;

    const PropertyMap userProperties;

    Date expirationDate;

    Object model;

    Document();

//    bool addChangeListener(ChangeDelegate delegate);
//    bool removeChangeListener(ChangeDelegate delegate);

    UnsavedRevision createRevision();

    SavedRevision update(UpdateDelegate delegate);

    bool deleteDoc();

    bool purge();

    const Object property(std::string key) const;

    const SavedRevision revision(std::string key) const;

//    bool putExistingRevisionWithProperties(PropertiesMap properties, std::map<std::string, Object> attachments, std::vector<std::string> revIDs, URL sourceURL, Error &error);

    SavedRevison putProperties(PropertyMap properties);
};

#endif // DOCUMENT_H
