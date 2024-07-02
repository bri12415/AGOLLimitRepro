// Copyright 2024 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#ifndef TOKENERRORREPRO_H
#define TOKENERRORREPRO_H

namespace Esri::ArcGISRuntime {
class Credential;
class Map;
class MapQuickView;
class Portal;
} // namespace Esri::ArcGISRuntime

#include <QObject>

Q_MOC_INCLUDE("MapQuickView.h")

class TokenErrorRepro : public QObject
{
    Q_OBJECT

  public:
    explicit TokenErrorRepro(QObject* parent = nullptr);
    ~TokenErrorRepro() override;
    Q_INVOKABLE void onCreatorClicked();
    Q_INVOKABLE void onFetchClicked();

  signals:
    void mapViewChanged();

  private:
    Esri::ArcGISRuntime::Portal* m_portal = nullptr;
    Esri::ArcGISRuntime::Credential* m_credential = nullptr;

    void createPortal(const QUrl& url);
};

#endif // TOKENERRORREPRO_H
