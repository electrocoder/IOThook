from django.contrib import admin

from datas.models import Data


class DataAdmin(admin.ModelAdmin):
    """
    """
    list_display = (
    'pk', 'user', 'device', 'field_1', 'field_2', 'field_3', 'field_4', 'field_5', 'field_6', 'field_7', 'field_8',
    'pub_date',)
    search_fields = ['device', ]

    def user(self, obj):
        return obj.device.user


admin.site.register(Data, DataAdmin)
