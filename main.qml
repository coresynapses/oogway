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
	spacing: 10

	
	TextInput {
	    id: username
	    text: "Username"
	    visible: true
	    
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
	    spacing: 20


	    Button {
		id: submit
		text: "Submit"
		visible: true
		
		background: Rectangle {
		    implicitWidth: 100
		    implicitHeight: 40
		    color: button.down ? "#000000" : "#ffffff"
		    border.color: "#26282a"
		    border.width: 1
		    radius: 4
		}
	    }
	    Button {
		id: cancel
		text: "Cancel"
		visible: true
		
		background: Rectangle {
		    implicitWidth: 100
		    implicitHeight: 40
		    color: button.down ? "#000000" : "#ffffff"
		    border.color: "#26282a"
		    border.width: 1
		    radius: 4
		}
	    }
	}
    }
}
