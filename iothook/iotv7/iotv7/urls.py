"""iotv7 URL Configuration
"""
from django.contrib import admin
from django.urls import include, path
from drf_yasg import openapi
from drf_yasg.views import get_schema_view
from rest_framework import permissions
from rest_framework import routers

from datas import views as datas

schema_view = get_schema_view(
    openapi.Info(
        title="IoThook Dashboard API",
        default_version='v1',
        description="IoThook Dashboard Web API",
        terms_of_service="https://iothook.com/en/privacy-policy/",
        contact=openapi.Contact(email="electrocoder@gmail.com"),
        license=openapi.License(name="MIT License"),
    ),
    public=True,
    permission_classes=[permissions.AllowAny, ],
)

router = routers.DefaultRouter()

urlpatterns = [
    path('', include(router.urls)),

    path('api/device/', datas.DataDeviceApiView.as_view()),  # Read
    path('api/update/', datas.DataUpdateApiView.as_view()),  # Write

    path('swagger<format>/', schema_view.without_ui(cache_timeout=0), name='schema-json'),
    path('swagger/', schema_view.with_ui('swagger', cache_timeout=0), name='schema-swagger-ui'),
    path('redoc/', schema_view.with_ui('redoc', cache_timeout=0), name='schema-redoc'),

    path('admin/', admin.site.urls),
]
