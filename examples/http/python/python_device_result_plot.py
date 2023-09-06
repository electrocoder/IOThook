# -*- coding: utf-8 -*-

"""
  Python ile IoThook REST Api Testi

  Kod çalıştırıldığında APIKEY ile doğrulama gerçekleştirilir.
  Cihaz api_key ile ilgili veriler IoThook a post edilir.

  Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
  testlerin yapilmasini amaclamaktadir.

  11 Eylul 2017
  Güncelleme : 19 Agustos 2019
  Sahin MERSIN

  Daha fazlasi icin

  http://www.iothook.com
  ve
  https://github.com/electrocoder/iotHook

  sitelerine gidiniz.

  Sorular ve destek talepleri icin
  https://github.com/electrocoder/iotHook/issues
  sayfasindan veya Meşe Bilişim den yardım alabilirsiniz.

  Yayin : http://mesebilisim.com

  Licensed under the Apache License, Version 2.0 (the "License").
  You may not use this file except in compliance with the License.
  A copy of the License is located at

  http://www.apache.org/licenses/
"""

import json
import pprint
import random
import time

from tkinter import *
from tkinter.ttk import Frame, Button, Label
import socket
import threading
import configparser

import requests
from matplotlib.backends.backend_tkagg import (
    FigureCanvasTkAgg, NavigationToolbar2Tk)
# Implement the default Matplotlib key bindings.
from matplotlib.backend_bases import key_press_handler
from matplotlib.figure import Figure

import numpy as np


class Window(Frame):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.master.title("IOTHOOK")
        self.pack(fill=BOTH, expand=True)

        self.master.protocol("WM_DELETE_WINDOW", self.on_closing)

        self.columnconfigure(1, weight=1)
        self.columnconfigure(3, pad=7)
        self.rowconfigure(3, weight=1)
        self.rowconfigure(5, pad=7)

        self.is_connect = False

        self.row = 0
        self.column = 0

        self.api_label = Label(self, text="API KEY")
        self.api_label.place(x=10, y=10)

        self.row = 0
        self.column += 1

        self.api_entry = Entry(self)
        self.api_entry.place(x=70, y=10)
        #
        # self.row = 0
        # self.column += 1
        #
        self.connect = Button(self, text="Connect", command=self.connect_command)
        self.connect.place(x=270, y=10)

        # self.row += 1
        # self.column = 0

        self.field_1_label = Label(self, text="Field 1")
        self.field_1_label.place(x=10, y=40)

        self.row += 0
        self.column += 1

        self.field_1 = Checkbutton(self, width=5)
        self.field_1.place(x=110, y=40)
        #
        # self.row += 1
        # self.column = 0
        #
        self.field_2_label = Label(self, text="Field 2")
        self.field_2_label.place(x=10, y=60)

        self.row += 0
        self.column += 1

        self.field_2 = Checkbutton(self, width=5)
        self.field_2.place(x=110, y=60)
        #
        # self.row += 1
        # self.column = 0
        #
        self.field_3_label = Label(self, text="Field 3")
        self.field_3_label.place(x=10, y=80)

        self.row += 0
        self.column += 1

        self.field_3 = Checkbutton(self, width=5)
        self.field_3.place(x=110, y=80)
        #
        # self.row += 1
        # self.column = 0
        #
        self.field_4_label = Label(self, text="Field 4")
        self.field_4_label.place(x=10, y=100)

        self.row += 0
        self.column += 1

        self.field_4 = Checkbutton(self, width=5)
        self.field_4.place(x=110, y=100)
        #
        # self.row += 1
        # self.column = 0
        #
        self.received_graph_label = Label(self, text="Received Data Graph")
        self.received_graph_label.place(x=10, y=140)

        self.row += 1
        self.column = 0

        self.fig = Figure(figsize=(6, 5), dpi=100)
        self.ax = self.fig.add_subplot(111)
        self.ax.grid()

        self.canvas = FigureCanvasTkAgg(self.fig, master=self)
        self.canvas.get_tk_widget().place(x=10, y=180)

    def thread_function(self):
        while True:
            API_KEY = 'ceb0024b84ff6fb7527d5506'  # demo hesap #17 random test
            url = 'http://iothook.com/api/device/?api_key=' + API_KEY + "&results=1"

            response = requests.get(url)
            data = response.json()
            print(data)
            print(len(data))
            print(data[0]['id'])

            # self.ax.cla()
            # self.ax.grid()
            # dpts = [random.randint(1, 100), random.randint(1, 100), random.randint(1, 10), random.randint(1, 10),
            #         random.randint(1, 10), random.randint(1, 10), random.randint(1, 10), random.randint(1, 10),
            #         random.randint(1, 10), random.randint(1, 10), ]
            # self.ax.plot(range(10), dpts, marker='o', color='orange')
            # self.canvas.draw()
            print("t")
            time.sleep(2)

    def connect_command(self):
        self.x = threading.Thread(target=self.thread_function, daemon=True)
        self.x.start()



    def on_closing(self):
        self.master.destroy()


def main():
    root = Tk()
    root.geometry("850x700+10+10")
    app = Window()
    root.mainloop()


if __name__ == '__main__':
    main()
