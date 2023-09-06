"""
WSGI config for iotv7 project.
"""

import os

from django.core.wsgi import get_wsgi_application

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'iotv7.settings')

application = get_wsgi_application()
