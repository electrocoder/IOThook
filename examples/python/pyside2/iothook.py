import requests
from PySide2.QtWidgets import *
from PySide2.QtUiTools import QUiLoader
from PySide2.QtCore import QFile, QTimer

from matplotlib.backends.backend_qt5agg import (
    FigureCanvas, NavigationToolbar2QT as NavigationToolbar)

from matplotlib.figure import Figure

import numpy as np
import random


class MplWidget(QWidget):

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)

        self.canvas = FigureCanvas(Figure())

        vertical_layout = QVBoxLayout()
        vertical_layout.addWidget(self.canvas)
        vertical_layout.addWidget(NavigationToolbar(self.canvas, self))

        self.canvas.axes = self.canvas.figure.add_subplot(111)
        self.setLayout(vertical_layout)


class MainWidget(QWidget):

    def __init__(self):
        QWidget.__init__(self)

        designer_file = QFile("iothook.ui")
        designer_file.open(QFile.ReadOnly)
        loader = QUiLoader()
        loader.registerCustomWidget(MplWidget)
        self.ui = loader.load(designer_file, self)
        designer_file.close()

        self.setWindowTitle("IOTHOOK")

        self.field_1_list = []
        self.field_2_list = []
        self.field_3_list = []
        self.field_4_list = []
        self.field_5_list = []
        self.field_6_list = []
        self.field_7_list = []
        self.field_8_list = []

        self.lineEdit = self.ui.findChild(QLineEdit, 'lineEdit')
        self.pushButton = self.ui.findChild(QPushButton, 'pushButton')

        self.pushButton.clicked.connect(self.result)

        grid_layout = QGridLayout()
        grid_layout.addWidget(self.ui)
        self.setLayout(grid_layout)

    def result(self):
        self.timer = QTimer()
        self.timer.setInterval(5000)
        self.timer.timeout.connect(self.status)
        self.timer.start()

    def status(self):
        print("update")
        # read api key
        # API_KEY = '4c8f1e0277c7f694e698739b'  # demo #230 5 channel test
        API_KEY = self.lineEdit.text()
        if API_KEY:
            self.pushButton.setText("Stop")
            url = 'http://iothook.com/api/device/?api_key=' + API_KEY + "&results=1"
            response = requests.get(url)
            data = response.json()
            print(data)

            try:
                self.ui.MplWidget.canvas.axes.clear()
                self.field_title_list = []

                if data[0]['field_1']:
                    self.field_title_list.append('field_1')
                    self.field_1_list.append(data[0]['field_1'])
                    self.ui.MplWidget.canvas.axes.plot(self.field_1_list)

                if data[0]['field_2']:
                    self.field_title_list.append('field_2')
                    self.field_2_list.append(data[0]['field_2'])
                    self.ui.MplWidget.canvas.axes.plot(self.field_2_list)

                if data[0]['field_3']:
                    self.field_title_list.append('field_3')
                    self.field_3_list.append(data[0]['field_3'])
                    self.ui.MplWidget.canvas.axes.plot(self.field_3_list)

                if data[0]['field_4']:
                    self.field_title_list.append('field_4')
                    self.field_4_list.append(data[0]['field_4'])
                    self.ui.MplWidget.canvas.axes.plot(self.field_4_list)

                if data[0]['field_5']:
                    self.field_title_list.append('field_5')
                    self.field_5_list.append(data[0]['field_5'])
                    self.ui.MplWidget.canvas.axes.plot(self.field_5_list)

                if data[0]['field_6']:
                    self.field_title_list.append('field_6')
                    self.field_6_list.append(data[0]['field_6'])
                    self.ui.MplWidget.canvas.axes.plot(self.field_6_list)

                if data[0]['field_7']:
                    self.field_title_list.append('field_7')
                    self.field_7_list.append(data[0]['field_7'])
                    self.ui.MplWidget.canvas.axes.plot(self.field_7_list)

                if data[0]['field_8']:
                    self.field_title_list.append('field_8')
                    self.field_8_list.append(data[0]['field_8'])
                    self.ui.MplWidget.canvas.axes.plot(self.field_8_list)

                self.ui.MplWidget.canvas.axes.legend((self.field_title_list), loc='upper right')
                self.ui.MplWidget.canvas.draw()

                self.repaint()
            except:
                pass


app = QApplication([])
window = MainWidget()
window.show()
app.exec_()
