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

#include "TokenErrorRepro.h"

#include "Map.h"
#include "OAuthClientInfo.h"
#include "CoreTypes.h"
#include "Credential.h"
#include "Portal.h"
#include "Error.h"
#include "ErrorException.h"
#include "CredentialCache.h"

#include <QFuture>

using namespace Esri::ArcGISRuntime;

TokenErrorRepro::TokenErrorRepro(QObject* parent /* = nullptr */):
  QObject(parent)
{
}

TokenErrorRepro::~TokenErrorRepro()
{
}

void TokenErrorRepro::onCreatorClicked()
{
  OAuthClientInfo oAuthInfo(QStringLiteral(/* The s_cientId from SecurityTest */), OAuthMode::User); /* The s_cientId from SecurityTest */
  oAuthInfo.setRefreshTokenExchangeInterval(1);
  m_credential = new Credential(oAuthInfo, this);
  createPortal(QUrl("https://www.arcgis.com"));
  m_portal->load();
}

void TokenErrorRepro::onFetchClicked()
{
  m_portal->fetchBasemapsAsync().then(
  [this]()
  {
    qDebug() << "Fetched at time" << QDateTime::currentDateTime().toString();
    qDebug() << "Token: " << m_portal->credential()->oAuthRefreshToken();
  }).onFailed(
  [](const ErrorException& e)
  {
    qDebug() << "Errored";
    qDebug() << e.error().message();
    qDebug() << e.error().additionalMessage();
  });
}

void TokenErrorRepro::createPortal(const QUrl& url)
{
  m_portal = new Portal(url, m_credential, this);

  connect(m_portal, &Portal::errorOccurred, this, [](const Error& error)
  {
    qDebug() << "Portal error:" << error.message() << error.additionalMessage();
  });

  connect(m_portal, &Portal::doneLoading, this, [](const Error& error)
  {
    if (!error.isEmpty())
    {
      qDebug() << error.message();
      qDebug() << error.additionalMessage();
    }
  });
}
