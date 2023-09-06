from django.contrib import admin

from devices.models import Device


class DeviceAdmin(admin.ModelAdmin):
    """
    """
    list_display = ('pk', 'user', 'name', 'slug', 'pub_date',)
    prepopulated_fields = {"slug": ("name",)}
    search_fields = ['name', ]


admin.site.register(Device, DeviceAdmin)
