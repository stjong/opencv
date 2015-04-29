import os;
import glob;
import xml.etree.ElementTree as ET

ET.register_namespace('', "http://schemas.microsoft.com/developer/msbuild/2003")
ET.register_namespace('m2', "http://schemas.microsoft.com/appx/2013/manifest")
ET.register_namespace('', "http://schemas.microsoft.com/appx/2010/manifest")

for root, dirnames, filenames in os.walk('bin'):
  for filename in filenames:
    if filename.endswith("appxManifest"):
      tree = ET.parse(os.path.join(root, filename))
      treeRoot = tree.getroot()
      # Add capabilities
      caps = ET.SubElement(treeRoot, "Capabilities")
      ET.SubElement(caps, "Capability", Name="documentsLibrary")

      # Add extensions support
      for item in treeRoot.findall('{http://schemas.microsoft.com/appx/2010/manifest}Applications'):
        apps = item.findall('{http://schemas.microsoft.com/appx/2010/manifest}Application')
        for app in apps:
          exts = ET.SubElement(app, "Extensions")
          ext = ET.SubElement(exts, "Extension", Category="windows.fileTypeAssociation")
          fileTypeAssociation = ET.SubElement(ext, "FileTypeAssociation", Name="config")
          supportedFileTypes = ET.SubElement(fileTypeAssociation, "SupportedFileTypes")
          fileType = ET.SubElement(supportedFileTypes, "FileType")
          fileType.text = ".log"
          tree.write(os.path.join(root, filename))

