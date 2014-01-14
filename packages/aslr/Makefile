include $(TOPDIR)/rules.mk

PKG_NAME:=aslr
PKG_VERSION:=master
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
	SECTION:=commotion
	CATEGORY:=Commotion
	SUBMENU:=Utilities
	DEPENDS:=+commotion
	TITLE:=ASLR Test
	URL:=https://commotionwireless.net/
endef

define Package/$(PKG_NAME)/description
	Simple test to confirm Address Space Layout Randomization.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/root
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/aslr $(1)/root
endef

$(eval $(call BuildPackage,aslr))
