# 30.05.2023

project = 'iothook'
copyright = '2023, iothook'
author = 'iothook'

release = '0.1'
version = '0.1.0'

# -- General configuration

extensions = [
    'sphinx.ext.duration',
    'sphinx.ext.doctest',
    'sphinx.ext.autodoc',
    'sphinx.ext.autosummary',
    'sphinx.ext.intersphinx',
]

intersphinx_mapping = {
    'python': ('https://docs.python.org/3/', None),
    'sphinx': ('https://www.sphinx-doc.org/en/master/', None),
}
intersphinx_disabled_domains = ['std']

templates_path = ['_templates']

# -- Options for HTML output

html_theme = 'bizstyle'

# -- Options for EPUB output
epub_show_urls = 'footnote'

master_doc = 'index'

language = 'en'

html_static_path = ['_static']

html_title = 'IoTHook IoT Internet Of Things Arduino, ESP, Raspberry Pi'

html_short_title = html_title

html_logo = '_static/internet-of-things.png'

html_favicon = '_static/internet-of-things.png'

html_show_sourcelink = True

html_sidebars = {
   '**': ['globaltoc.html', 'sourcelink.html', 'searchbox.html'],
   'using/windows': ['windowssidebar.html', 'searchbox.html'],
}
