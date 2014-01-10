include $(TOPDIR)/rules.mk

PKG_NAME:=ssp
PKG_VERSION:=master
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
  SECTION:=commotion
  CATEGORY:=Commotion
  SUBMENU:=Utilities
  DEPENDS:=+commotion +commotion-gui
  TITLE:=SSP Test
  URL:=https://commotionwireless.net/
endef

define Package/$(PKG_NAME)/description
  Simple buffer overflow to test new ssp option in commotion-router
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./ssp/* $(PKG_BUILD_DIR)/
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/root
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ssp/smash $(1)/root
endef

define Build/InstallDev
endef

CO_BUILD_PACKAGES += ssp

$(foreach b,$(CO_BUILD_PACKAGES),$(eval $(call BuildPackage,$(b))))

