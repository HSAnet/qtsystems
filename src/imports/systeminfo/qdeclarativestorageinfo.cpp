/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtSystems module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qdeclarativestorageinfo_p.h"

QT_BEGIN_NAMESPACE

/*!
    \qmlclass StorageInfo QDeclarativeStorageInfo
    \inqmlmodule QtSystemInfo
    \ingroup qml-systeminfo
    \brief The StorageInfo element provides various information about the storage system.
*/

/*!
    \internal
*/
QDeclarativeStorageInfo::QDeclarativeStorageInfo(QObject *parent)
    : QObject(parent)
    , storageInfo(new QStorageInfo(this))
{
}

/*!
    \internal
 */
QDeclarativeStorageInfo::~QDeclarativeStorageInfo()
{
}

/*!
    \qmlproperty stringlist StorageInfo::allLogicalDrives

    This property holds a list of all the available logical drives.
*/
QStringList QDeclarativeStorageInfo::allLogicalDrives() const
{
    connect(storageInfo, SIGNAL(logicalDriveChanged(QString,bool)), this, SIGNAL(logicalDriveChanged(QString,bool)));
    return storageInfo->allLogicalDrives();
}

/*!
    \qmlmethod qlonglong StorageInfo::availableDiskSpace(string drive)

    Returns the available free space on the \a drive, in bytes. -1 is returned if the drive doesn't
    exist, or the information is not available.
*/
qlonglong QDeclarativeStorageInfo::availableDiskSpace(const QString &drive) const
{
    return storageInfo->availableDiskSpace(drive);
}

/*!
    \qmlmethod qlonglong StorageInfo::totalDiskSpace(string drive)

    Returns the total space of the \a drive, in bytes. -1 is returned if the drive doesn't exist,
    or the information is not available.
*/
qlonglong QDeclarativeStorageInfo::totalDiskSpace(const QString &drive) const
{
    return storageInfo->totalDiskSpace(drive);
}

/*!
    \qmlmethod qlonglong StorageInfo::uriForDrive(string drive)

    Returns the URI, or unique identifier for the given \a drive. If the drive doesn't exist, or the
    information is not available, an empty string is returned.
*/
QString QDeclarativeStorageInfo::uriForDrive(const QString &drive) const
{
    return storageInfo->uriForDrive(drive);
}

/*!
    \qmlmethod DriveType StorageInfo::driveType(string drive)

    Returns the type of the given \a drive. Possible values are:
    \list
    \li UnknownDrive    Drive type unknown.
    \li InternalDrive   Internal mass storage drive, e.g. hard drive.
    \li RemovableDrive  Removable drive, e.g. memory card.
    \li RemoteDrive     Network drive.
    \li CdromDrive      CD-ROM.
    \li RamDrive        Virtual drive made in RAM memory.
    \endlist
*/
int QDeclarativeStorageInfo::driveType(const QString &drive) const
{
    return storageInfo->driveType(drive);
}

QT_END_NAMESPACE
