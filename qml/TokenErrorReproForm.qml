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

import QtQuick
import QtQuick.Controls
import Esri.TokenErrorRepro
import Esri.ArcGISRuntime.Toolkit

Item {
    id: mainItem
    // Declare the C++ instance which creates the map etc. and supply the view
    TokenErrorRepro {
        id: model
    }

    AuthenticationView {
        anchors.centerIn: parent
    }

    Button {
        id: creator
        anchors.top: mainItem.top
        anchors.left: mainItem.left
        text: qsTr("Create portal with credentials")
        contentItem: Text {
            text: creator.text
            color: "black"
        }
        onClicked: {
            model.onCreatorClicked();
        }
    }

    Button {
        id: fetcher
        text: qsTr("Fetch basemaps")
        anchors.top: creator.bottom
        anchors.left: mainItem.left
        contentItem: Text {
            text: fetcher.text
            color: "black"
        }
        onClicked: {
            model.onFetchClicked();
        }
    }
}
