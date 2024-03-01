import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts
import QtQuick.Window

ApplicationWindow {
    width: 800
    height: 800
    visible: true


    ColumnLayout {
	id: layout
	anchors.fill: parent
	spacing: 200

	Label {
	    id: login_header
	    text: "Oogway Log-In"
	    Layout.margins: 50
	    Layout.fillWidth: true
	}
	
	TextInput {
	    id: username
	    text: "Username"
	    Layout.margins: 50
	    Layout.fillWidth: true
	    
	    width: 400
	    height: 50
	    color: "#ff0000"
	    
	}
	TextInput {
	    id: password
	    text: "Password"
	    visible: true
	    
	    width: 400
	    height: 50
	    color: "#00ff00"
	    
	}
	TextInput {
	    id: two_fa_code
	    text: "2FA Code"
	    visible: true
	    
	    width: 400
	    height: 50
	    color: "#0000ff"
	    
	}

	RowLayout {
	    id: control_buttons
	    spacing: 200


	    Button {
		id: submit
		text: "Submit"
		visible: true
		Layout.margins: 50
		Layout.fillWidth: true
		
		background: Rectangle {
		    implicitWidth: 100
		    implicitHeight: 40
		    color: submit.down ? "#ff0000" : "#00ffff"
		    border.color: "#00ffff"
		    border.width: 1
		    radius: 4
		}
	    }
	    Button {
		id: cancel
		text: "Cancel"
		visible: true
		Layout.margins: 50
		Layout.fillWidth: true
		
		background: Rectangle {
		    implicitWidth: 100
		    implicitHeight: 40
		    color: cancel.down ? "#00ff00" : "#ff00ff"
		    border.color: "#ffff00"
		    border.width: 1
		    radius: 4
		}
	    }
	}
    }
}
