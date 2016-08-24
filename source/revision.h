#ifndef REVISION_H
#define REVISION_H

#include <vector>
#include <string>

class SavedRevision;

class UnsavedRevision;

class Revision
{
public:
//    const std::vector<std::string> attachmentNames;

//    const std::vector<Attachment> attachments;

    const Database* database;

    const Document* document;

    const std::string id;

    const bool isDeletion;

    const std::string parentId;

    const SavedRevision parent;

    const std::vector<SavedRevision> revisionHistory;

    const PropertyMap properties;

    const PropertyMap userProperties;

    Revision();

//    Attachment getAttachment(std::string name);

    Object getProperty(std::string id);
};

class UnsavedRevison : Revision
{
public:
    bool isDeletion;

    PropertyMap properties;

    PropertyMap userProperties;

//    bool removeAttachment(std::string name);

    SavedRevision save();

    SavedRevision save(bool allowConflict);

    bool setAttachment(std::string name, std::string contentType, Url contentUrl);

    bool setAttachment(std::string name, std::string contentType, Object content);
};

class SavedRevision : Revision
{
public:
    const bool propertiesAvailable;

    UnsavedRevision createRevision() const;

    SavedRevision createRevision(PropertyMap properties) const;

    SavedRevision deleteDocument();
};

#endif // REVISION_H
